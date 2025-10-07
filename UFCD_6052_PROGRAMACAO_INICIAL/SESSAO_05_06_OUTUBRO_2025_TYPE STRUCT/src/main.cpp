#include <Arduino.h>

// Estrutura Variavel Botao
typedef struct Botao

{
  int periferico;
  int estado;
};
Botao Botao1;
Botao Botao2;


 typedef struct Leds

 {
  int periferico;
 };
 
 Leds Led_azul;
 Leds Led_vermelho;


int baudRate = 9600;

// Variável case 
int caso = 0;

// Funções para cada caso 
void Caso_0() { // Botão 1 pressionado -> LED AZUL ligado
  Serial.println("Botao1 pressionado -> LED AZUL ON");
  digitalWrite(Led_azul.periferico, HIGH);
  digitalWrite(Led_vermelho.periferico, LOW);
}

void Caso_1() { // Botão 2 pressionado -> LED VERMELHO ligado
  Serial.println("Botao2 pressionado -> LED VERMELHO ON");
  digitalWrite(Led_azul.periferico, LOW);
  digitalWrite(Led_vermelho.periferico, HIGH);
}

void Caso_2() { // Ambos pressionados -> Ambos LEDs ligados
  Serial.println("Ambos pressionados -> AMBOS LEDs ON");
  digitalWrite(Led_azul.periferico, HIGH);
  digitalWrite(Led_vermelho.periferico, HIGH);
}

void Caso_3() { // Nenhum pressionado -> Ambos desligados
  Serial.println("Nenhum botao pressionado -> AMBOS LEDs OFF");
  digitalWrite(Led_azul.periferico, LOW);
  digitalWrite(Led_vermelho.periferico, LOW);
}

void setup() {
  Serial.begin(baudRate);
  Serial.println("--- Código sem debounce (simples) ---");

  // Configurar as portas para o Botao
  Botao1.periferico = A0;
  Botao2.periferico = A1;

  // Input Botoes
  pinMode(Botao1.periferico, INPUT);
  pinMode(Botao2.periferico, INPUT);

  Led_azul.periferico = 2;
  Led_vermelho.periferico = 3;
  
  // Output dos LEDs
  pinMode(Led_azul.periferico, OUTPUT);
  pinMode(Led_vermelho.periferico, OUTPUT);

  // LEDs inicialmente desligados
  digitalWrite(Led_azul.periferico, LOW);
  digitalWrite(Led_vermelho.periferico, LOW);
}

void loop() {
  // Leitura Botoes
  Botao1.estado = digitalRead(Botao1.periferico);
  Botao2.estado = digitalRead(Botao2.periferico);

  // Determina 'caso' com as regras pedidas
  if (Botao1.estado == LOW && Botao2.estado == HIGH) {
    caso = 0; // botão 1 pressionado -> Caso 0
  } else if (Botao1.estado == HIGH && Botao2.estado == LOW) {
    caso = 1; // botão 2 pressionado -> Caso 1
  } else if (Botao1.estado == LOW && Botao2.estado == LOW) {
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
      digitalWrite(Led_azul.periferico, LOW);
      digitalWrite(Led_vermelho.periferico, LOW);
      break;
  }


  delay(1000);
}