#include <Arduino.h>

const int BAUT_RATE = 9600;
const int botao_direita = A0;
const int botao_esquerda = A1;


void setup() {
  // CONFIGURAR PORTA SERIE
  Serial.begin(BAUT_RATE);
  
  // Input dos botoes
  pinMode(botao_direita, INPUT_PULLUP);
  pinMode(botao_esquerda, INPUT_PULLUP);
}

void loop() {

  // LER ESTADO DOS BOTÕES
  int estado_direita = digitalRead(botao_direita);
  int estado_esquerda = digitalRead(botao_esquerda);

  // SE NENHUM BOTÃO ESTIVER PRESSIONADO
  if (estado_direita == HIGH && estado_esquerda == HIGH) {
    Serial.println("MECANISMO TRABALHA");
  }

  // SE BOTÃO DIREITA FOR PRESSIONADO
  if (estado_direita == LOW) {
    Serial.println("FIM DE CURSO DIREITA");
  }

  // SE BOTÃO ESQUERDA FOR PRESSIONADO
  if (estado_esquerda == LOW) {
    Serial.println("FIM DE CURSO ESQUERDA");
  }

  delay(1000);
}