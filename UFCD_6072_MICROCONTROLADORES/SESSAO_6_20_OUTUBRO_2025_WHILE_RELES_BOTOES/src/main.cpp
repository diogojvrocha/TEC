#include <Arduino.h>

int baud_rate = 9600;


typedef struct Rele
{
  int estado;
  int periferico;
};
Rele reles[4];


typedef struct Botao
{
  int estado;
  int periferico;
  int valor;
};
Botao botoes[4];


int contar = 0;

void setup()
{
  Serial.begin(9600);

  // Setup porta reles
  reles[0].periferico = 2;
  reles[1].periferico = 3;
  reles[2].periferico = 4;
  reles[3].periferico = 5;

  // Setup porta botoes
  botoes[0].periferico = A0;
  botoes[1].periferico = A1;
  botoes[2].periferico = A2;
  botoes[3].periferico = A3;

  while (contar < 4)  
  {
    // ESTADO DOS BOTOES
    botoes[contar].estado = 0;

    // ESTADO DOS RELES
    reles[contar].estado = 0;

    // PINMODES
    pinMode(botoes[contar].periferico, INPUT);
    pinMode(reles[contar].periferico, OUTPUT);

    contar++;
  }
  
}


void loop()
{
  while (contar < 4)
  {
    // LEITURA DO ESTADO DO BOTAO
    botoes[contar].estado = !digitalRead(botoes[contar].periferico);
    Serial.print("b");
    Serial.print(contar);
    Serial.print(" - ");
    Serial.println(botoes[contar].estado);

    // SE O ESTADO DO BOTAO FOR x, RELE VAI ABRIR
    if (botoes[contar].estado)
    {
      digitalWrite(reles[contar].periferico, HIGH);  
      Serial.println("!--- RELE ABERTO ---!");
    }
    // CASO CONTRARIO, RELE FECHA
    else
    {
      Serial.println("RELE FECHADO");
      digitalWrite(reles[contar].periferico, LOW);
    }
    contar++;
  }

  delay(1000);
  
}