#include <Arduino.h>

int baud_rate = 9600;

typedef struct Temporizador
{
  unsigned long tempoanterior;
  unsigned long intervalo;
};
Temporizador temporizador1; 



void setup() {

  Serial.begin(9600);

  temporizador1.tempoanterior = 0;
  
  temporizador1.intervalo = 1000;

}

void loop() {


  if(millis() - temporizador1.tempoanterior > temporizador1.intervalo)
  {
    Serial.println("Executar");
  }
  


}

