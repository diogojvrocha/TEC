#include <Arduino.h>

int baud_rate = 9600;

unsigned long int tempoactual = 0;
unsigned long int tempoanterior = 0;


unsigned long int tempoactual_2 = 0;
unsigned long int tempoanterior_2 = 0;

unsigned long int tempoactual_3 = 0;
unsigned long int tempoanterior_3 = 0;

int periferico = 2;
int periferico_2 = 3;
int periferico_3 = 4;

void setup() {
  Serial.begin(9600);
  pinMode(periferico, OUTPUT);
  pinMode(periferico_2, OUTPUT);
  pinMode(periferico_3, OUTPUT);
  
 
}

void loop() {
  tempoactual = millis();
  
  if(tempoactual - tempoanterior > 1000)
  {
    Serial.print("tempo_actual - ");
    Serial.println(tempoactual);

    Serial.print("tempo_anterior - ");
    Serial.println(tempoanterior);

    if(digitalRead(periferico) == LOW)
    {
      digitalWrite(periferico, HIGH);
    
    }
    else
    {
      digitalWrite(periferico, LOW);
    }

    tempoanterior = millis();
  }

  
  
  tempoactual_2 = millis();
  
  if(tempoactual_2 - tempoanterior_2 > 2000)
  {
    Serial.print("tempo_actual_2 - ");
    Serial.println(tempoactual_2);

    Serial.print("tempo_anterior_2 - ");
    Serial.println(tempoanterior_2);

    if(digitalRead(periferico_2) == LOW)
    {
      digitalWrite(periferico_2, HIGH);
    
    }
    else
    {
      digitalWrite(periferico_2, LOW);
    }

    tempoanterior_2 = millis();
  }


  tempoactual_3 = millis();
  
  if(tempoactual_3 - tempoanterior_3 > 3000)
  {
    Serial.print("tempo_actual_3 - ");
    Serial.println(tempoactual_3);

    Serial.print("tempo_anterior_3 - ");
    Serial.println(tempoanterior_3);

    if(digitalRead(periferico_3) == LOW)
    {
      digitalWrite(periferico_3, HIGH);
    
    }
    else
    {
      digitalWrite(periferico_3, LOW);
    }

    tempoanterior_3 = millis();
  }

}
