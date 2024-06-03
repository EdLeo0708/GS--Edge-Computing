#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHTesp.h>

// Configurações do sensor e do display
const int DHTPin = 15; // Pino de conexão do sensor DHT22
const int pHpin = 35; // Pino de conexão do sensor de pH
const int turbidityPin = 34; // Pino de conexão do sensor de turbidez
const float defaultPH = 7.0; // Valor padrão de pH quando o sensor não está conectado
const float calibration_value = 21.34 - 0.7; // Valor de calibração do sensor de pH

// Configurações do LCD
const int i2c_addr = 0x27; // Endereço I2C do display LCD
const int lcdColumns = 16; // Número de colunas do display LCD
const int lcdRows = 2; // Número de linhas do display LCD

// Inicializa o sensor DHT e o display LCD
DHTesp dhtSensor; // Objeto para o sensor DHT
LiquidCrystal_I2C lcd(i2c_addr, lcdColumns, lcdRows); // Objeto para o display LCD

void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  dhtSensor.setup(DHTPin, DHTesp::DHT22); // Configura o sensor DHT22 no pino especificado
  lcd.init(); // Inicializa o display LCD
  lcd.backlight(); // Liga a luz de fundo do display LCD
}

void loop() {
  TempAndHumidity newValues = dhtSensor.getTempAndHumidity(); // Lê os valores de temperatura e umidade do sensor DHT

  // Sensor de pH
  int pHval = analogRead(pHpin); // Lê o valor analógico do sensor de pH
  float pH;
  if (pHval < 10) { // Verifica se o sensor de pH não está conectado
    pH = defaultPH; // Define o valor padrão de pH
    Serial.println("Sensor de pH não encontrado"); // Exibe mensagem no monitor serial
    lcd.clear(); // Limpa o display LCD
    lcd.setCursor(0, 0); // Define a posição do cursor no display LCD
    lcd.print("pH: Sensor Não"); // Exibe mensagem no display LCD
    lcd.setCursor(0, 1); // Define a posição do cursor na segunda linha do display LCD
    lcd.print("Conectado"); // Exibe mensagem no display LCD
  } else {
    float voltage = pHval * (3.3 / 4096.0); // Converte o valor analógico para tensão
    pH = -5.70 * voltage + calibration_value; // Calcula o valor de pH usando a fórmula de calibração
    Serial.println("Sensor de pH Conectado"); // Exibe mensagem no monitor serial
    lcd.clear(); // Limpa o display LCD
    lcd.setCursor(0, 0); // Define a posição do cursor no display LCD
    lcd.print("pH: "); // Exibe mensagem no display LCD
    lcd.print(pH, 2); // Exibe o valor de pH com duas casas decimais no display LCD
  }

  // Sensor de Turbidez
  int turbidityValue = analogRead(turbidityPin); // Lê o valor analógico do sensor de turbidez
  float turbidity = calculateTurbidity(turbidityValue); // Calcula o valor de turbidez usando a função calculateTurbidity()

  // Exibe temperatura e umidade
  lcd.setCursor(0, 1); // Define a posição do cursor na segunda linha do display LCD
  lcd.print("Temp: "); // Exibe mensagem no display LCD
  lcd.print(newValues.temperature, 1); // Exibe a temperatura com uma casa decimal no display LCD
  lcd.print("C Umidade: "); // Exibe mensagem no display LCD
  lcd.print(newValues.humidity, 1); // Exibe a umidade com uma casa decimal no display LCD

  // Exibe valores de pH e turbidez
  lcd.setCursor(0, 0); // Define a posição do cursor no display LCD
  lcd.print("pH: "); // Exibe mensagem no display LCD
  lcd.print(pH, 2); // Exibe o valor de pH com duas casas decimais no display LCD
  lcd.print(" Turb: "); // Exibe mensagem no display LCD
  lcd.print(turbidity, 2); // Exibe o valor de turbidez com duas casas decimais no display LCD

  delay(20000); // Aguarda 20 segundos antes de continuar para o próximo ciclo do loop
}

float calculateTurbidity(int turbidityValue) {
  // Implemente sua lógica de cálculo de turbidez aqui
  // Substitua este espaço reservado pelo seu cálculo de turbidez real
  return map(turbidityValue, 0, 750, 100, 0); // Mapeia o valor do sensor para um valor de turbidez
}