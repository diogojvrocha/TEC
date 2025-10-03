#include <Arduino.h>

const int BAUT_RATE = 9600;
const int botao_direita = A0;
const int botao_esquerda = A1;


void setup() {
  // CONFIGURAR PORTA SERIE
  Serial.begin(BAUT_RATE);
}

void loop() {
  // ENQUANTO O BOTÃO NÃO ESTÁ PRESSIONADO
  while (botao_direita == LOW)
  Serial.println("MECANISMO TRABALHA")
  {
    // SE BATER NO BOTÃO/ BOTÃO PRESSIONADO
    if (botao_direita || botao_esquerda == LOW)
    {
      /* code */
    }
    
  }
  
}

// put function definitions here:
 {
 
}