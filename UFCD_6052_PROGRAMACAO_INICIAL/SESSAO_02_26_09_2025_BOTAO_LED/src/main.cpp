#include <Arduino.h>

int botao = A0;
int led = 2;
int estado_do_botao = 0;

void setup() 
{
Serial.begin(115200);

pinMode(botao, INPUT);
pinMode(led, OUTPUT);
}

void loop()
{
  Serial.println(digitalRead(botao));
  if (digitalRead(botao) == LOW)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  delay(100);
}