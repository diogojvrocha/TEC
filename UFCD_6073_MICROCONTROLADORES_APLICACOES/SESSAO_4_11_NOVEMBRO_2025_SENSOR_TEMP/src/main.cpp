#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2       // Agora o sensor está ligado no A0
#define DHTTYPE DHT11   // Tipo de sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Leitura de temperatura e humidade com DHT11 (A0)");
  dht.begin();
}

void loop() {
  delay(5000); // Aguarda 5 segundos entre leituras

  float humidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(humidade) || isnan(temperatura)) {
    Serial.println("Falha ao ler o sensor DHT11!");
    return;
  }

  Serial.print("Humidade: ");
  Serial.print(humidade);
  Serial.print(" %\t");

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
}