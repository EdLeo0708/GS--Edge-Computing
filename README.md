# GS--Edge-Computing

## Inicialização e Configuração:

- Configura e inicializa o display LCD via comunicação I2C.
- Configura o sensor de temperatura e umidade DHT22.
- Define os pinos de conexão para os sensores de pH e turbidez.


## bibliotecas utilizadas:

- *'LiquidCrystal I2C:'*


  Facilita a comunicação e o controle do display LCDs

- *'DHT sensor library for ESPx:'*


  O controle de sensores de temperatura especificamente em placas como *ESP32* e *ESP8266*

- *'ArduinoJson:'*


  Facilita a criação, análises e manipulação de dados com em formato JSON 

- *'Wire:'*,


  Comunicação i2c entre arduino e outros dispositíveis com I2C


## Leitura dos Sensores:

- faz a leitura dos valores de temperatura e umidade do sensor DHT22.
- Lê o valor analógico do sensor de pH.
- Lê o valor analógico do sensor de turbidez.


## Processamento dos Dados:

- Converte o valor analógico do sensor de pH para um valor de pH utilizando uma fórmula de calibração.
- Converte o valor analógico do sensor de turbidez para um valor de turbidez usando a função 'calculateTurbidity'.


## Serialização e Envio dos Dados em Formato JSON:

- Cria um objeto JSON contendo os valores de temperatura, umidade, pH e turbidez.
- Serializa o objeto JSON em uma string.
- Envia a string JSON para o monitor serial, permitindo a leitura dos dados de forma estruturada.


## Ciclo de Operação:

Esperar 20 segundos antes de repetir o ciclo, lendo novamente os valores dos sensores e atualizando o display LCD e o monitor serial.
Fisicamente, aqui estão as ações específicas dos componentes envolvidos:

- **ESP32**:

  Executa o código, lê os valores dos sensores conectados aos seus pinos analógicos e digitais, e controla o display LCD.
- **Display LCD (I2C)**:

  Exibe os valores de temperatura, umidade, pH e turbidez.
- **Sensor DHT22**:

  Mede a temperatura e a umidade do ambiente.
- **Sensor de pH**:

  Mede o nível de pH de uma solução líquida.
- **Sensor de Turbidez**:

  Mede a turbidez (claridade/opacidade) de uma solução líquida.
- **Monitor Serial**:
  
  Exibe os dados coletados e processados em formato JSON para fins de monitoramento e depuração.


  ###***LINK***
  - [wokwi](https://wokwi.com/projects/399260778570895361)
