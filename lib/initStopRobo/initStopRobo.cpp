#include <Arduino.h>
#include <pins.h>
#include "initStopRobo.h"
#include "config.h"
#include "misc.h"

// Função de inicialização dos motores usando botão:
void initMotores()
{
    // Testando motores para frente e para trás com PWM
    for (size_t j = 1; j < 4; j++)
    {
        for (size_t i = 0; i < 3; i += 2)
        {
            analogWrite(MOTORES[i], 0 + (j * 50)); // bobinas frente
        }
        delay(100);
        if (j == 3)
        {
            analogWrite(MOTORES[1] | MOTORES[3], 0); // bobinas frente
        }
    }
    for (size_t j = 0; j < 4; j++)
    {
        for (size_t i = 0; i < 3; i += 2)
        {
            analogWrite(MOTORES[i], 0 + (j * 50)); // bobinas trás de 150 a 0
        }
        if (j == 3)
        {
            analogWrite(MOTORES[0] | MOTORES[2], 0); // bobinas trás
        }
        delay(100);
    }
}

void corridaMotores()
{
    analogWrite(MOTORES[0], 255); // motor esquerdo frente
    analogWrite(MOTORES[2], 255); // motor direito frente
}

// Função de parada do robo:
void paradaRobo()
{
    // Desliga todos os motores
    for (size_t i = 0; i < 4; i++)
    {
        analogWrite(MOTORES[i], 0);
    }
}