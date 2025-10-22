#include <Arduino.h>
#include "config.h"
#include "leituraSensores.h"

// Função de configuração dos sensores:

void configSensores() {
  // Código para configurar os sensores
  pinMode(LE, INPUT);
  pinMode(CE, INPUT);
  pinMode(CD, INPUT);
  pinMode(LD, INPUT);
  pinMode(LDR, INPUT);
}

void lerSensores( int tamanho) {
  // Código para ler os sensores 
  Serial.println("Lendo sensores...");
  for (int i = 0; i < tamanho; i++)
  {
    valorSensores[i] = analogRead(SENSORES[i]); // Leitura analógica dos sensores
  }
}