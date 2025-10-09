#include <Arduino.h>

int baud_rate = 9600;

///////////////////////////////

// Variavel millis
unsigned long int tempoactual = 0;
unsigned long int tempoanterior = 0;


// Variavel led
int led = 2;

// Variavel botao
int botao = A0;

int comecar_contagem = 0;

void setup() {

  Serial.begin(9600);

  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  
}

void loop() {

tempoactual = millis();

if(digitalRead(botao) == LOW)
{
  comecar_contagem = 1;
}

if(comecar_contagem && (tempoactual - tempoanterior > 2000))
{
 digitalWrite(led, HIGH);

 comecar_contagem = 0;
}




 
  


}
