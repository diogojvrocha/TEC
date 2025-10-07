#include <Arduino.h>

const int BAUD_RATE = 9600;

int estado_do_botao = 0;
int temperatura_lida = 10;
int temperatura_maxima = 5;
int temperatura_minima = 1;

int botao_arranque_1 = 1;
int botao_arranque_2 = 1;

int sobrecarga = 0;

void setup() 
{
  Serial.begin(BAUD_RATE);
}

void loop() 
{
  if (temperatura_lida > temperatura_maxima)
  {
    Serial.println("ligar ventoinha");
  }
  else
  {
    Serial.println("desligar ventoinha");
  }
  if (temperatura_lida < temperatura_minima)
  {
    Serial.println("Ligar esquentador");
  }
  else
  {
    Serial.println("Desligar esquentador");
  }
  if (estado_do_botao == 0)
  {
    Serial.println("Botao pressionado");
  }
  else
  {
    Serial.println("Botao nao pressionado");
  }
  if (botao_arranque_1 && botao_arranque_2)
  {
    Serial.println("Ligar maquina");
  }
  else
  {
    Serial.println("Desligar maquina");
  }
  if (temperatura_lida > temperatura_maxima || sobrecarga)
  {
    Serial.println("Desligar maquina");
  }
  else
  {
    Serial.println("Continuar ligada");
  }
  
delay(2000);
}