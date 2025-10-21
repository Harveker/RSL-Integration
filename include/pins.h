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
#define PWMIN1 9
#define PWMIN2 6
#define PWMIN3 11
#define PWMIN4 10
// Pinos dos sensores de linha
#define LE A5
#define CE A4
#define CD A3
#define LD A2
#define LDR A1
// Array com os pinos dos sensores
const int SENSORES[5] = {LE, CE, CD, LD, LDR};