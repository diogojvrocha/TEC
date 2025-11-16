#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2        // pino do sensor (podes usar A0 se quiseres)
#define DHTTYPE DHT11   // tipo do sensor

#define LED_VERMELHO 8
#define LED_BRANCO   9
#define LED_AZUL     10

// Definir limites de temperatura
#define TEMP_BAIXA 20.0   // abaixo disto = frio
#define TEMP_ALTA  24.0   // acima disto = quente

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Leitura de temperatura e LEDs de estado");

  dht.begin();

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_BRANCO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

  // Inicialmente apaga todos os LEDs
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_BRANCO, LOW);
  digitalWrite(LED_AZUL, LOW);
}

void loop() {
  delay(2000);

  float humidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(humidade) || isnan(temperatura)) {
    Serial.println("Falha ao ler o sensor DHT11!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  Serial.print("Humidade: ");
  Serial.print(humidade);
  Serial.println(" %");

  // Controle dos LEDs conforme a temperatura
  if (temperatura < TEMP_BAIXA) {
    digitalWrite(LED_AZUL, HIGH);     // frio → azul
    digitalWrite(LED_BRANCO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
  } 
  else if (temperatura > TEMP_ALTA) {
    digitalWrite(LED_VERMELHO, HIGH); // quente → vermelho
    digitalWrite(LED_BRANCO, LOW);
    digitalWrite(LED_AZUL, LOW);
  } 
  else {
    digitalWrite(LED_BRANCO, HIGH);   // normal → branco
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AZUL, LOW);
  }
}
