#include <Arduino.h>

const int BAUD_RATE = 9600;

// Variaveis Leitura Botoes
int botao1 = A0;
int botao2 = A1;

// Variaveis Botoes
int estado_botao1 = 0;
int estado_botao2 = 0;

// Variavel LEDs
int led1 = 2;
int led2 = 3;

// Variavel Opcao Switch Case
int opcao = 0;

// Funcao Desligar os LEDs
void desligar_leds()
{
  Serial.println("Nenhum botao esta pressionado");
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

// Funcao Desligar os LEDs
void desligar_led_direita()
{
  Serial.println("Nenhum botao esta pressionado");
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void setup() {
  
  // config. porta série
  Serial.begin(9600);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {

  //Leitura dos Botoes
  estado_botao1 = digitalRead(botao1);
  estado_botao2 = digitalRead(botao2);

  // Mostra Ecra "Bem vindo"
  if (estado_botao1 && estado_botao2) 
  {
    opcao = 0;
  }
  
  // Seleciona Café Curto
  if (estado_botao1 && !estado_botao2) 
  {
    opcao = 1;
  }

   // Seleciona Café Longo
  if (!estado_botao1 && estado_botao2) 
  {
    opcao = 2;
  }

   // Seleciona Café Médio
  if (!estado_botao1 && !estado_botao2) 
  {
    opcao = 3;
  }

  switch (opcao)
  {
  case 0:
    // Mostrar Ecra "Bem Vindo"
    Serial.println("Bem vindo");
    break;
    
    case 1:
    // Café Curto
    Serial.println("Café Curto");
    break;

    case 2:
    // Café Longo
    Serial.println("Café Longo");
    break;

    case 3:
    // Café Medio
    Serial.println("Café Médio");
    break;
  default:
  // Ecra a mostrar um erro
  Serial.println("Erro");
  break;
  }

delay(1000);
}

