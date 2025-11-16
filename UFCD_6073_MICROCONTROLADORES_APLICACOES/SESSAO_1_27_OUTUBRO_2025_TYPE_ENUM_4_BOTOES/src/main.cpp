#include <Arduino.h>

int baudRate = 9600;

// Enum Switch Case
typedef enum Caso
{
  STANDBY = 0,
  CIMA,
  DIREITA,
  BAIXO,
  ESQUERDA,
};
Caso opcao;

// estrutura botao
typedef struct Botao
{
  int estado;
  int periferico;
};
Botao botoes[4];


// estrutura led
typedef struct Leds
{
  int estado;
  int periferico;
};
Leds led[4];



// variavel index
int index = 0;

void setup()
{
  Serial.begin(9600);

  // Porta dos botoes
  botoes[0].periferico = A0;
  botoes[1].periferico = A1;
  botoes[2].periferico = A2;
  botoes[3].periferico = A3;

  // Porta dos Leds
  led[0].periferico = 2;
  led[1].periferico = 3;
  led[2].periferico = 4;
  led[3].periferico = 5;

  // Index dos botoes
  while (index < 4)
  {
    // Estado do botao
    botoes[index].estado = LOW;

    // Estado do led
    led[index].estado = LOW;

    // Pinmode do botao
    pinMode(botoes[index].periferico, INPUT_PULLUP);

    // Pinmode do led
    pinMode(led[index].periferico, OUTPUT);

    index++;
  }
  
}



void loop()
{
  index = 0;

    // WHILE DO ESTADO DOS BOTOES TODOS
    while (index < 4)
    {
      botoes[index].estado = !digitalRead(botoes[index].periferico);
      index++;
    }

    // CONDICOES DOS 4 BOTOES PRIMARIOS
    if (!botoes[0].estado && !botoes[1].estado && !botoes[2].estado && !botoes[3].estado)
    {
      opcao = STANDBY;
    }

    if (botoes[0].estado && !botoes[1].estado && !botoes[2].estado && !botoes[3].estado)
    {
      opcao = CIMA;
    }

    if (!botoes[0].estado && botoes[1].estado && !botoes[2].estado && !botoes[3].estado)
    {
      opcao = DIREITA;
    }

     if (!botoes[0].estado && !botoes[1].estado && botoes[2].estado && !botoes[3].estado)
    {
      opcao = BAIXO;
    }

     if (!botoes[0].estado && !botoes[1].estado && !botoes[2].estado && botoes[3].estado)
    {
      opcao = ESQUERDA;
    }

  // CONDICOES DOS LEDS
  index = 0;
  while (index < 4)
  {
    led[index].estado = LOW;
    digitalWrite(led[index].periferico, LOW);
    index++;
  }


    // SWITCH CASE COM AS OPCOES PARA IMPRIMIR NO SERIAL MONITOR
    switch (opcao)
    {

    // CASO DO "STANDBY" (SEM PRESSIONAR ALGUM BOTAO)
    case 0:
      Serial.println("STANDBY");
      break;
    
    // CASOS DOS 4 BOTOES PRIMARIOS
    case 1:
      Serial.println("CIMA");
      digitalWrite(led[0].periferico, HIGH);
      break;
    
    case 2:
      Serial.println("DIREITA");
      digitalWrite(led[1].periferico, HIGH);
      break;
    
    case 3:
      Serial.println("BAIXO");
      digitalWrite(led[2].periferico, HIGH);
      break;
    
    case 4:
      Serial.println("ESQUERDA");
      digitalWrite(led[3].periferico, HIGH);
      break;

    default:
      break;
    }
  delay(1000);
}