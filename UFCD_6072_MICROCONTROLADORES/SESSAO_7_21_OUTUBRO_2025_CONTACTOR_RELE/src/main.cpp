#include <Arduino.h>

int baud_rate = 9600;


typedef struct Contactor
{
  int estado;      
  int periferico;  
};
Contactor contactor1;

typedef struct Rele
{
  int estado;      
  int periferico;  
};
Rele reles;


typedef struct Botao
{
  int estado;      
  int periferico;  
};
Botao botoes;



void setup()
{
  Serial.begin(9600);

  // Setup porta Reles 
  reles.periferico = A0;
  reles.estado = LOW;
  pinMode(reles.periferico, OUTPUT);
  digitalWrite(reles.periferico, reles.estado); 

  // Setup porta Contactor 
  contactor1.periferico = 7;
  pinMode(contactor1.periferico, INPUT_PULLUP);
  contactor1.estado = LOW; // Inicia como "desligado"

  // Setup Botoes 
  botoes.periferico = 5;
  botoes.estado = HIGH; // (HIGH - Nao esta pressionado)
  pinMode(botoes.periferico, INPUT_PULLUP);
}


void loop()
{
  // Leitura estado do botão (com pull-up: pressionado - LOW), invertemos para ter 1 = pressionado
  botoes.estado = !digitalRead(botoes.periferico); 

  // Se botão pressionado - Abre o relé
  if (botoes.estado)
  {
   digitalWrite(reles.periferico, HIGH);
  }
  // Se não, Fecha
  else
  {
   digitalWrite(reles.periferico, LOW);
  }

  // Leitura estado relé
  reles.estado = digitalRead(reles.periferico);

  // Leitura estado contactor
  int contato_leitura = digitalRead(contactor1.periferico);
  contactor1.estado = (contato_leitura == LOW) ? HIGH : LOW; // HIGH = contactor fechado

  // Mensagem Serial
  Serial.print("Botao: ");
  Serial.print(botoes.estado ? "PRESSIONADO" : "SOLTO");
  Serial.print("  | Rele (A0): ");
  Serial.print(reles.estado ? "ON" : "OFF");
  Serial.print("  | Contactor (feedback p7): ");

  // se relé estiver LIGADO mas contactor NAO
  if (reles.estado && !contactor1.estado) {
    Serial.println("RELE LIGADO, contactor NAO ACIONADO!");
  } else {
    Serial.println(contactor1.estado ? "ACIONADO" : "DESLIGADO");
  }

  delay(1000);
}