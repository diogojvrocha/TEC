#include <Arduino.h>
int botao = 11;
int led = 13;

void setup() {
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(botao) == HIGH) {   
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}