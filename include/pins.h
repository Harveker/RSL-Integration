#pragma once
#include <Arduino.h>

// Definição dos pinos utilizados no robô
#define DISPA 3
#define DISPB 5
#define DISPC 4
#define DISPD 2
// Pino do botão
#define BOTAO 7
// Pino do buzzer
#define BUZZER 8
// Pinos dos motores
#define PWMIN1 9    // Pino do motor esquerdo
#define PWMIN2 6    // Pino do motor esquerdo
#define PWMIN3 11   // Pino do motor direito
#define PWMIN4 10   // Pino do motor direito
const int MOTORES[4] = {PWMIN1, PWMIN2, PWMIN3, PWMIN4};
// Pinos dos sensores de linha
#define LE A5   // Sensor esquerdo
#define CE A4   // Sensor central esquerdo
#define CD A3   // Sensor central direito
#define LD A2   // Sensor direito
#define LDR A1  // Sensor de luz ambiente
// Array com os pinos dos sensores
const int SENSORES[5] = {LE, CE, CD, LD, LDR};

int valorSensores[5] = {0, 0, 0, 0, 0}; // Array para armazenar os valores lidos dos sensores
int valorButao = 0; // Variável para armazenar o estado do botão