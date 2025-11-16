#include <Arduino.h>
#include <DHT.h>

int baudRate = 9600;

// ---- DHT11 ----
#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ---- LM35 ----
#define LM35PIN A4

// Enum Switch Case
typedef enum Caso
{
  STANDBY = 0,
  CIMA,
  DIREITA,
  BAIXO,
  ESQUERDA,
};
Caso opcao;

// estrutura botao
typedef struct Botao
{
  int estado;
  int periferico;
};
Botao botoes[4];

// estrutura led
typedef struct Leds
{
  int estado;
  int periferico;
};
Leds led[4];

// variavel index
int index = 0;

void setup()
{
  Serial.begin(9600);

  // Iniciar o sensor
  dht.begin();     

  // Porta dos botoes
  botoes[0].periferico = A0;
  botoes[1].periferico = A1;
  botoes[2].periferico = A2;
  botoes[3].periferico = A3;

  // Porta dos Leds
  led[0].periferico = 2;
  led[1].periferico = 3;
  led[2].periferico = 4;
  led[3].periferico = 5;

  // Index dos botoes e leds
  while (index < 4)
  {
    botoes[index].estado = LOW;
    led[index].estado = LOW;

    pinMode(botoes[index].periferico, INPUT_PULLUP);
    pinMode(led[index].periferico, OUTPUT);

    index++;
  }
}

void loop()
{
  index = 0;

  // Ler todos os botões
  while (index < 4)
  {
    botoes[index].estado = !digitalRead(botoes[index].periferico);
    index++;
  }

  // Condições dos botões
  if (!botoes[0].estado && !botoes[1].estado && !botoes[2].estado && !botoes[3].estado)
    opcao = STANDBY;

  if (botoes[0].estado && !botoes[1].estado && !botoes[2].estado && !botoes[3].estado)
    opcao = CIMA;

  if (!botoes[0].estado && botoes[1].estado && !botoes[2].estado && !botoes[3].estado)
    opcao = DIREITA;

  if (!botoes[0].estado && !botoes[1].estado && botoes[2].estado && !botoes[3].estado)
    opcao = BAIXO;

  if (!botoes[0].estado && !botoes[1].estado && !botoes[2].estado && botoes[3].estado)
    opcao = ESQUERDA;



  // Ler DHT11 (uma vez só por loop)
  float temperatura = dht.readTemperature();
  float humidade = dht.readHumidity();
  bool leituraValida = !(isnan(temperatura) || isnan(humidade));

   // Ler LM35 
  int valorLM35 = analogRead(LM35PIN);
  float voltage = valorLM35 * (5.0 / 1023.0);  // tensão em volts
  float tempLM35 = voltage * 100.0;           // LM35 = 10mV por grau
  
  // SWITCH CASE COM DHT11 e LM35
  switch (opcao)
  {
    case STANDBY:
      Serial.println("STANDBY");
    // Reset aos LEDs
    index = 0;
    while (index < 4)
      {
        digitalWrite(led[index].periferico, LOW);
        index++;
      }
      break;

    case CIMA:
      Serial.println("CIMA");
      digitalWrite(led[0].periferico, HIGH);

      if (leituraValida) {
        Serial.print("Temperatura (DHT11): ");
        Serial.print(temperatura);
        Serial.println(" °C");
      }
      break;

    case DIREITA:
      Serial.println("DIREITA");
      digitalWrite(led[1].periferico, HIGH);

      if (leituraValida) {
        Serial.print("Humidade: ");
        Serial.print(humidade);
        Serial.println(" %");
      }
      break;

    case BAIXO:
      Serial.println("BAIXO");
      digitalWrite(led[2].periferico, HIGH);

      if (leituraValida) {
        Serial.print("Temperatura (DHT11): ");
        Serial.print(temperatura);
        Serial.print(" °C | Humidade: ");
        Serial.print(humidade);
        Serial.println(" %");
      }
      break;

    case ESQUERDA:
      Serial.println("ESQUERDA");
      digitalWrite(led[3].periferico, HIGH);

      Serial.print("Temperatura (LM35): ");
      Serial.print(tempLM35);
      Serial.println(" °C");
      break;

    default:
      break;
  }

  delay(1000);
}
