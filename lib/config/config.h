#pragma once
//macro de debug, comente para sumir com o debug
#define DEBUG
//macro de debug para os valores dos sensores, comente para sumir com o debug
#define DEBUG_SENSORES

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
#define PWMIN1 9    // Pino do motor esquerdo tras
#define PWMIN2 6    // Pino do motor esquerdo frente
#define PWMIN3 11   // Pino do motor direito frente
#define PWMIN4 10   // Pino do motor direito tras
const int MOTORES[4] = {PWMIN1, PWMIN2, PWMIN3, PWMIN4};
// Pinos dos sensores de linha
#define LE A5   // Sensor esquerdo
#define CE A4   // Sensor central esquerdo
#define CD A3   // Sensor central direito
#define LD A2   // Sensor direito
#define LDR A1  // Sensor de luz ambiente
// Array com os pinos dos sensores
const int SENSORES[5] = {LE, CE, CD, LD, LDR};
extern const char* rotulos[];

// Numero de sensores
const int NUM_SENSORES = sizeof(SENSORES)/sizeof(SENSORES[0]);
//variaveis globais
extern int valorButao;
struct valorSensores {
    int status[NUM_SENSORES];
} typedef vS;

extern unsigned long timer;
//maquina de estados de direção
enum Direcao {
    PARADO,
    FRENTE,
    ESQUERDA,
    ESQUERDACURTA,
    DIREITA,
    DIREITACURTA
};

void initConfig();