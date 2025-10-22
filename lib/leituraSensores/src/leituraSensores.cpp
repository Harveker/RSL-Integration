#include <Arduino.h>
#include "config.h"
#include "leituraSensores.h"

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
  Serial.println("Lendo sensores...");
  for (int i = 0; i < 5; i++)
  {
    valorSensores[i] = analogRead(SENSORES[i]); // Leitura analógica dos sensores
    /* switch (i)
    {
    case 0:
      Serial.println("LE :");
      Serial.println(valorSensores[i]);
      break;
    case 1:
      Serial.println("CE :");
      Serial.println(valorSensores[i]);
      break;
    case 2:
      Serial.println("CD :");
      Serial.println(valorSensores[i]);
      break;
    case 3:
      Serial.println("LD :");
      Serial.println(valorSensores[i]);
      break;
    case 4:
      Serial.println("LDR :");
      Serial.println(valorSensores[i]);
      break;
    default:
      break;
    } */
  }
}