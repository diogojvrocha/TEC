#include <Arduino.h>

// Struct Botoes
typedef struct botao
{
  int periferico;
  int estado;
};

botao botao1;
botao botao2;
botao botao3;
botao botao4;


// Variavel Baud rate
int baudRate = 9600;

// Funcoes botao
void caso_0(){// Nenhum botão pressionado - 
  Serial.println("standby -- DPAD Enabled");
   }

void caso_1(){// botao1 pressionado - "UP"
  Serial.println("Arrow_UP");
   }

void caso_2(){// botao2 pressionado - "DOWN"
  Serial.println("Arrow_DOWN");
   }

void caso_3(){// botao3 pressionado - "LEFT"
  Serial.println("Arrow_LEFT");
   }

void caso_4(){// botao4 pressionado - "RIGHT"
  Serial.println("Arrow_RIGHT");
   }


// Variavel Case
int caso = 0;



void setup() {

 Serial.begin(9600);

 // Portas dos botoes
 botao1.periferico = A0;
 botao2.periferico = A1;
 botao3.periferico = A2;
 botao4.periferico = A3;

 // Input dos botoes
 pinMode(botao1.periferico, INPUT_PULLUP);
 pinMode(botao2.periferico, INPUT_PULLUP);
 pinMode(botao3.periferico, INPUT_PULLUP);
 pinMode(botao4.periferico, INPUT_PULLUP);
}

void loop() {

  // Leitura dos botoes
  botao1.estado = digitalRead(botao1.periferico);
  botao2.estado = digitalRead(botao2.periferico);
  botao3.estado = digitalRead(botao3.periferico);
  botao4.estado = digitalRead(botao4.periferico);
  

  // Casos Switch Case
  if (botao1.estado == HIGH && botao2.estado == HIGH && botao3.estado == HIGH
  && botao4.estado == HIGH)
  {
    caso = 0;
    // IDLE - SEM CARREGAR EM NENHUM BOTAO (Standby - DPAD ENABLED - executa o caso 0)
  }

  else if (botao1.estado == LOW)
  {
    caso = 1;
    // botao1 (UP - executa o caso 1)
  }

  else if (botao2.estado == LOW)
  {
    caso = 2;
    // botao2 (DOWN - executa o caso 2)
  }

  else if (botao3.estado == LOW)
  {
    caso = 3;
    // botao3 (LEFT - executa o caso 3)
  }

  else if (botao4.estado == LOW)
  {
    caso = 4;
    // botao4 (RIGHT - executa o caso 4)
  }

  
switch (caso)
{
case 0:
  caso_0();
  break;

case 1:
  caso_1();
  break;

case 2:
  caso_2();
  break;

case 3:
  caso_3();
  break;

case 4:
  caso_4();
  break;


default:
  Serial.println("ERRO");
  break;
}

delay (800);
}

