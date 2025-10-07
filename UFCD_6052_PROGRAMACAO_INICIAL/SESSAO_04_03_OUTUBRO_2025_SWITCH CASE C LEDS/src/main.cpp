#include <Arduino.h>

// Variavel Botoes
int Botao1 = A0;
int Botao2 = A1;

// Variavel LEDs
int Led_azul = 2;
int Led_vermelho = 3;

const int baudRate = 9600;

// Variável case
int caso = 0;

// Funções case
void Caso_0() { // Botão 1 pressionado -> LED azul ligado
  Serial.println("Botao1 pressionado -> LED AZUL ON");
  digitalWrite(Led_azul, HIGH);
  digitalWrite(Led_vermelho, LOW);
}

void Caso_1() { // Botão 2 pressionado -> LED vermelho ligado
  Serial.println("Botao2 pressionado -> LED VERMELHO ON");
  digitalWrite(Led_azul, LOW);
  digitalWrite(Led_vermelho, HIGH);
}

void Caso_2() { // Ambos pressionados, Ambos LEDs ligados
  Serial.println("Ambos pressionados -> AMBOS LEDs ON");
  digitalWrite(Led_azul, HIGH);
  digitalWrite(Led_vermelho, HIGH);
}

void Caso_3() { // Nenhum pressionado, Ambos desligados
  Serial.println("Nenhum botao pressionado -> AMBOS LEDs OFF");
  digitalWrite(Led_azul, LOW);
  digitalWrite(Led_vermelho, LOW);
}

void setup() {
  Serial.begin(baudRate);
  Serial.println("--- Código sem debounce (simples) ---");

  pinMode(Botao1, INPUT);
  pinMode(Botao2, INPUT);

  pinMode(Led_azul, OUTPUT);
  pinMode(Led_vermelho, OUTPUT);

  // LEDs inicialmente desligados
  digitalWrite(Led_azul, LOW);
  digitalWrite(Led_vermelho, LOW);
}

void loop() {

  // Leitura botoes
  int estado1 = digitalRead(Botao1);
  int estado2 = digitalRead(Botao2);

  // Instruções
  if (estado1 == LOW && estado2 == HIGH) {
    caso = 0; // botão 1 pressionado -> Caso 0
  } else if (estado1 == HIGH && estado2 == LOW) {
    caso = 1; // botão 2 pressionado -> Caso 1
  } else if (estado1 == LOW && estado2 == LOW) {
    caso = 2; // ambos pressionados -> Caso 2
  } else {
    caso = 3; // nenhum pressionado -> Caso 3 (LEDs OFF)
  }

  // Executa o caso usando SWITCH (mesma estrutura)
  switch (caso) {
    case 0:
      Caso_0();
      break;

    case 1:
      Caso_1();
      break;

    case 2:
      Caso_2();
      break;

    case 3:
      Caso_3();
      break;

    default:
      Serial.println("Erro");
      digitalWrite(Led_azul, LOW);
      digitalWrite(Led_vermelho, LOW);
      break;
  }

  delay(1000);
}