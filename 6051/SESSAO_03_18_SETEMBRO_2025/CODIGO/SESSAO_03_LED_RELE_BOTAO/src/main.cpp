#include <Arduino.h>

// Pino do relé
const int relePin = A5;

// Pino do LED (inverso do relé)
const int ledPin = A4;

// Pino do botão
const int botaoPin = 2;

// Tempos (ms)
const unsigned long TEMPO_NORMAL = 2000;
const unsigned long TEMPO_RAPIDO = 500;

// Debounce
const unsigned long DEBOUNCE_MS = 50;
unsigned long ultimoTempoLeitura = 0;
int ultimoEstadoBotao = HIGH;
int estadoBotaoEstavel = HIGH;

// Controle do relé
unsigned long ultimoTempoToggle = 0;
bool releEstado = false;

void setup() {
  Serial.begin(9600); // Inicializa comunicação serial para debug

  pinMode(relePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(botaoPin, INPUT_PULLUP); // botão entre porta 2 e GND

  // estado inicial
  digitalWrite(relePin, LOW);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  // Leitura com debounce do botão (INPUT_PULLUP: LOW = pressionado)
  int leitura = digitalRead(botaoPin);
  if (leitura != ultimoEstadoBotao) {
    ultimoTempoLeitura = millis();
    ultimoEstadoBotao = leitura;
  }
  if ((millis() - ultimoTempoLeitura) > DEBOUNCE_MS) {
    if (estadoBotaoEstavel != ultimoEstadoBotao) {
      estadoBotaoEstavel = ultimoEstadoBotao;
    }
  }

  // Define o intervalo conforme o estado do botão
  unsigned long intervalo = (estadoBotaoEstavel == LOW) ? TEMPO_RAPIDO : TEMPO_NORMAL;

  // Debug: imprime estado do botão e intervalo
  Serial.print("Botao: ");
  Serial.print(estadoBotaoEstavel == LOW ? "Pressionado" : "Solto");
  Serial.print(" | Intervalo: ");
  Serial.println(intervalo);

  // Alterna o relé conforme o intervalo
  if (millis() - ultimoTempoToggle >= intervalo) {
    ultimoTempoToggle = millis();
    releEstado = !releEstado;

    digitalWrite(relePin, releEstado ? HIGH : LOW);
    digitalWrite(ledPin, releEstado ? LOW : HIGH);
  }
}