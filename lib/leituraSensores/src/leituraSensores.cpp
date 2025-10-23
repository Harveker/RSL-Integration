#include <Arduino.h>
#include "config.h"
#include "leituraSensores.h"
#include "misc.h"

// Função de configuração dos sensores:

void configSensores()
{
  // Código para configurar os sensores
  pinMode(LE, INPUT);
  pinMode(CE, INPUT);
  pinMode(CD, INPUT);
  pinMode(LD, INPUT);
  pinMode(LDR, INPUT);
}



void lerSensores()
{
  // Código para ler os sensores
  debugEstado("Lendo sensores...");
  for (int i = 0; i < 5; i++)
  {
    valorSensores[i] = analogRead(SENSORES[i]); // Leitura analógica dos sensores

    #ifdef DEBUG_SENSORES
    // Print all sensors in one line
    unsigned long agora = millis();
    if (agora - timer >= 500UL)
    {
      Serial.print("Sensores: ");
      for (int i = 0; i < 5; i++)
      {
        Serial.print(rotulos[i]);
        Serial.print("=");
        Serial.print(valorSensores[i]);
        Serial.print("  ");
      }
      Serial.println();
      timer = agora;
    }
    #endif
  }
}