#include <Arduino.h>

int baud_rate = 9600;

typedef struct Temporizador
{
  unsigned long tempoanterior;
  unsigned long intervalo;
};
Temporizador temporizador1; 


typedef struct Rele
{
  int periferico;
  int estado;
  Temporizador temporizador;
};
Rele rele1;




void setup() {

  Serial.begin(9600);

  // Setup Temporizador
  temporizador1.tempoanterior = 0;
  temporizador1.intervalo = 1000;

  // Setup Intervalo Rele
  rele1.temporizador.tempoanterior = 0;
  rele1.temporizador.intervalo = 5000;

  // Porta do rele
  rele1.periferico = 3;
  pinMode(rele1.periferico, OUTPUT);

  // Estado do rele
  rele1.estado = LOW;
  digitalWrite(rele1.periferico, rele1.estado);

}



void loop() {


  if(millis() - rele1.temporizador.tempoanterior > rele1.temporizador.intervalo)
  {
    if (digitalRead(rele1.periferico))
    {
      digitalWrite(rele1.periferico, LOW);
      Serial.println("Desligado");
    }
    else
    {
      digitalWrite(rele1.periferico, HIGH);
      Serial.println("Ligado");
    }
    rele1.temporizador.tempoanterior = millis();
    
  }
  


}

