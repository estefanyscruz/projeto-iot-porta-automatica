# Sistema de Abertura Automática de Portas com IoT

Projeto desenvolvido utilizando ESP32, sensor PIR, servo motor e protocolo MQTT para simular a abertura automática de portas.

## Componentes Utilizados

- ESP32
- Sensor PIR
- Servo Motor SG90

## Tecnologias Utilizadas

- Arduino IDE
- MQTT
- HiveMQ
- Wokwi
- Linguagem C/C++

## Funcionamento

O sensor PIR detecta a presença de movimento. Quando um movimento é identificado, o ESP32 aciona o servo motor para simular a abertura da porta.

Após alguns segundos, a porta é fechada automaticamente. O sistema também envia mensagens MQTT informando os estados da porta.

## Broker MQTT

- Host: broker.hivemq.com
- Porta: 1883

## Pinos Utilizados

- Sensor PIR → GPIO 13
- Servo Motor → GPIO 18

## Simulação

Projeto desenvolvido e testado na plataforma Wokwi.

Link da simulação:
https://wokwi.com/projects/465391070046296065

## Autora

Estefany Cruz
