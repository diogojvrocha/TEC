#include <Arduino.h>

const int BAUT_RATE = 9600;
const int led = A0;

void setup() {
Serial.begin(BAUT_RATE);
pinMode(led, INPUT);

}

void loop() {
  // enquanto o botao está a ser pressionado
while (digitalRead(A0) == LOW)
{
  // contar mais um
  Serial.println("Contar mais um");

  // esperar 500
  delay(500);
}

}
