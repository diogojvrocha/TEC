#include <Arduino.h>

const int BAUD_RATE = 9600;
const int botao = 7;
int opcao = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
if (digitalRead(botao) == LOW)
{

}
  switch (opcao)
  {
  case 0:
    // Caso a temperatura fique acima dos 25ºC
    Serial.println("Temperatura acima dos 25ºC");
    break;
    
    case 1:
    // Caso a temperatura fique Alta
    Serial.println("Temperatura Alta");
    break;

    case 2:
    // Caso a temperatura fique Baixa
    Serial.println("Temperatura Baixa");
    break;
  
  default:
  // Caso não tenha opção
  Serial.println("Não tem opcao");
  break;
  delay(500);
  }
}

