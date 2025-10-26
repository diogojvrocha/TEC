#include <Arduino.h>

int baud_rate = 9600;

// Estrutura Temporizador
typedef struct Temporizador
{
    unsigned long tempo_anterior;
    unsigned long tempo_intervalo;
};
Temporizador temporizador;


// Estrutura Rele
typedef struct Rele
{
    int periferico;
    int estado;
    Temporizador temporizador;
};

Rele rele[4];





void setup()
{
    Serial.begin(9600);

    // Setup Tempo Intervalo Rele_0
    rele[0].temporizador.tempo_anterior = 0;
    rele[0].temporizador.tempo_intervalo = 5000;

    // Porta Rele_0
    rele[0].periferico = 3;
    pinMode(rele[0].periferico, OUTPUT);

    // Estado Rele_0
    rele[0].estado = LOW;
    digitalWrite(rele[0].periferico, rele[0].estado);

//-------------------------------------------------//

    // Setup Tempo Intervalo Rele_1
    rele[1].temporizador.tempo_anterior = 0;
    rele[1].temporizador.tempo_intervalo = 8000;

    // Porta Rele_1
    rele[1].periferico = 4;
    pinMode(rele[1].periferico, OUTPUT);

    // Estado Rele_1
    rele[1].estado = LOW;
    digitalWrite(rele[1].periferico, rele[1].estado);

//-------------------------------------------------//

    // Setup Tempo Intervalo Rele_2
    rele[2].temporizador.tempo_anterior = 0;
    rele[2].temporizador.tempo_intervalo = 11000;

    // Porta Rele_2
    rele[2].periferico = 5;
    pinMode(rele[2].periferico, OUTPUT);

    // Estado Rele_2
    rele[2].estado = LOW;
    digitalWrite(rele[2].periferico, rele[2].estado);



}

void loop()
{
    // Rele_0 Instrucoes

    if (millis() - rele[0].temporizador.tempo_anterior > rele[0].temporizador.tempo_intervalo)
    {
      if (digitalRead(rele[0].periferico))
      {
        digitalWrite(rele[0].periferico, LOW);
        Serial.println("Rele_0 -- Desligou");
      }
      else
      {
        digitalWrite(rele[0].periferico, HIGH);
        Serial.println("Rele_0 -- Ligou");
      }

      rele[0].temporizador.tempo_anterior = millis();
    }


    // Rele_1 Instrucoes

     if (millis() - rele[1].temporizador.tempo_anterior > rele[1].temporizador.tempo_intervalo)
    {
      if (digitalRead(rele[1].periferico))
      {
        digitalWrite(rele[1].periferico, LOW);
        Serial.println("Rele_1 -- Desligou");
      }
      else
      {
        digitalWrite(rele[1].periferico, HIGH);
        Serial.println("Rele_1 -- Ligou");
      }

      rele[1].temporizador.tempo_anterior = millis();
    }
    
    // Rele_2 Instrucoes

     if (millis() - rele[2].temporizador.tempo_anterior > rele[2].temporizador.tempo_intervalo)
    {
      if (digitalRead(rele[2].periferico))
      {
        digitalWrite(rele[2].periferico, LOW);
        Serial.println("Rele_2 -- Desligou");
      }
      else
      {
        digitalWrite(rele[2].periferico, HIGH);
        Serial.println("Rele_2 -- Ligou");
      }

      rele[2].temporizador.tempo_anterior = millis();
    }
    
        
}
