#include <Arduino.h>
#include "config.h"
#include <Arduino.h>

int valorSensores[5] = {0, 0, 0, 0, 0}; // Array para armazenar os valores lidos dos sensores
int valorButao = 0; // Variável para armazenar o estado do botão

void initConfig()
{
    // Código para inicializar botões, buzzer e motores
    // Configuração do pino do botão
    pinMode(BOTAO, INPUT);
    // Configuração do pino do buzzer
    pinMode(BUZZER, OUTPUT);
    // Configuração dos pinos dos motores
    pinMode(PWMIN1, OUTPUT);
    pinMode(PWMIN2, OUTPUT);
    pinMode(PWMIN3, OUTPUT);
    pinMode(PWMIN4, OUTPUT);
    // Inicialização dos motores em estado desligado
    analogWrite(PWMIN1, 0);
    analogWrite(PWMIN2, 0);
    analogWrite(PWMIN3, 0);
    analogWrite(PWMIN4, 0);
    // Inicialização do buzzer em estado desligado
    digitalWrite(BUZZER, LOW);
    // Outras configurações iniciais podem ser adicionadas aqui
    
}
