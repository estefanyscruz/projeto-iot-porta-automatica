#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Servo.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

Servo porta;

const int pirPin = 13;
const int servoPin = 18;

void conectarWiFi() {
Serial.print("Conectando ao Wi-Fi");

WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}

Serial.println("\nWi-Fi conectado!");
}

void conectarMQTT() {
while (!client.connected()) {


Serial.print("Conectando ao broker MQTT...");

String clientId = "ESP32-Porta-";
clientId += String(random(0xffff), HEX);

if (client.connect(clientId.c_str())) {

  Serial.println(" conectado!");

  client.publish(
    "estefany/porta/status",
    "ESP32 conectado ao broker MQTT"
  );

} else {

  Serial.print(" erro=");
  Serial.println(client.state());

  delay(5000);
}

}
}

void setup() {

Serial.begin(115200);

pinMode(pirPin, INPUT);

porta.attach(servoPin);
porta.write(0);

conectarWiFi();

client.setServer(mqtt_server, mqtt_port);

conectarMQTT();

Serial.println("Sistema iniciado com MQTT");
}

void loop() {

if (!client.connected()) {
conectarMQTT();
}

client.loop();

int movimento = digitalRead(pirPin);

if (movimento == HIGH) {


Serial.println("Movimento detectado!");

client.publish(
  "estefany/porta/movimento",
  "Movimento detectado"
);

client.publish(
  "estefany/porta/status",
  "Porta aberta"
);

porta.write(90);

delay(5000);

porta.write(0);

client.publish(
  "estefany/porta/status",
  "Porta fechada"
);

Serial.println("Porta fechada");

}

delay(100);
}
