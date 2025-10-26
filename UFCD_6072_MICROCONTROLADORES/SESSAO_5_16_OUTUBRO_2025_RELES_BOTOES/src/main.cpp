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
};
Botao botoes[4];


void setup()
{
  Serial.begin(9600);

  // Setup porta reles_0
  reles[0].periferico = 2;
  reles[0].estado = LOW;
  pinMode(reles[0].periferico, OUTPUT);


  // Setup porta botoes_0
  botoes[0].periferico = A0;
  botoes[0].estado = HIGH;
  pinMode(botoes[0].periferico, INPUT);

  //-------------------------------------//

  // Setup porta reles_1
  reles[1].periferico = 3;
  reles[1].estado = LOW;
  pinMode(reles[1].periferico, OUTPUT);


  // Setup porta botoes_1
  botoes[1].periferico = A1;
  botoes[1].estado = HIGH;
  pinMode(botoes[1].periferico, INPUT);

  //-------------------------------------//

  // Setup porta reles_2
  reles[2].periferico = 4;
  reles[2].estado = LOW;
  pinMode(reles[2].periferico, OUTPUT);


  // Setup porta botoes_2
  botoes[2].periferico = A2;
  botoes[2].estado = HIGH;
  pinMode(botoes[2].periferico, INPUT);
  
  //-------------------------------------//

  // Setup porta reles_3
  reles[3].periferico = 5;
  reles[3].estado = LOW;
  pinMode(reles[3].periferico, OUTPUT);


  // Setup porta botoes_3
  botoes[3].periferico = A3;
  botoes[3].estado = HIGH;
  pinMode(botoes[3].periferico, INPUT);
}


void loop()
{
  // Funcao Botao -- 0
  botoes[0].estado = !digitalRead(botoes[0].periferico);
  Serial.print("b0 - ");
  Serial.println(botoes[0].estado);


  if (botoes[0].estado)
  {
   digitalWrite(reles[0].periferico, HIGH);  
   Serial.println("!--- RELE LIGADO ---!");
  }
  else
  {
    Serial.println("RELE DESLIGADO");
   digitalWrite(reles[0].periferico, LOW);
  }

  //-------------------------------------//
  
  // Funcao Botao -- 1
  botoes[1].estado = !digitalRead(botoes[1].periferico);
  Serial.print("b1 - ");
  Serial.println(botoes[1].estado);


  if (botoes[1].estado)
  {
   digitalWrite(reles[1].periferico, HIGH);  
   Serial.println("!--- RELE LIGADO ---!");
  }
  else
  {
    Serial.println("RELE DESLIGADO");
   digitalWrite(reles[1].periferico, LOW);
  }
  
  //-------------------------------------//
  
  // Funcao Botao -- 2
  botoes[2].estado = !digitalRead(botoes[2].periferico);
  Serial.print("b2 - ");
  Serial.println(botoes[2].estado);


  if (botoes[2].estado)
  {
   digitalWrite(reles[2].periferico, HIGH);  
   Serial.println("!--- RELE LIGADO ---!");
  }
  else
  {
    Serial.println("RELE DESLIGADO");
   digitalWrite(reles[2].periferico, LOW);
  }
  
  //-------------------------------------//
  
  // Funcao Botao -- 3
  botoes[3].estado = !digitalRead(botoes[3].periferico);
  Serial.print("b3 - ");
  Serial.println(botoes[3].estado);


  if (botoes[3].estado)
  {
   digitalWrite(reles[3].periferico, HIGH);  
   Serial.println("!--- RELE LIGADO ---!");
  }
  else
  {
    Serial.println("RELE DESLIGADO");
   digitalWrite(reles[3].periferico, LOW);
  }
  
  delay(1000);
  
}