#include <Arduino.h>
#include "initStopRobo.h"
#include "config.h"
#include "misc.h"

// Função de inicialização dos motores usando botão:
void initMotores()
{
    // Testando motores para frente e para trás com PWM
    Serial.println("Iniciando teste dos motores...");
    Serial.println("Indo para frente...");
    for (size_t j = 1; j < 4; j++)
    {

        analogWrite(MOTORES[1], 0 + (j * 50)); // bobinas frente
        analogWrite(MOTORES[2], 0 + (j * 50)); // bobinas frente
        Serial.print("Valor PWM: ");
        Serial.println(0 + (j * 50));
        delay(600);
        if (j == 3)
        {
            delay(1000);
        }
    }
    analogWrite(MOTORES[1], 0); // bobinas frente
    analogWrite(MOTORES[2], 0); // bobinas frente

    Serial.println("Aguardando botão para continuar...");

    while (!debounceBotao()){}     // Espera o botão ser pressionado novamente para continuar

    Serial.println("Continuando teste dos motores...");
    Serial.println("Indo para trás...");

    for (size_t j = 0; j < 4; j++)
    {

        analogWrite(MOTORES[0], 0 + (j * 50)); // bobinas trás de 150 a 0
        analogWrite(MOTORES[3], 0 + (j * 50)); // bobinas trás de 150 a 0
        Serial.print("Valor PWM: ");
        Serial.println(0 + (j * 50));
        delay(600);
        if (j == 3)
        {
            delay(1000);
        }
    }

    analogWrite(MOTORES[0], 0); // bobinas trás
    analogWrite(MOTORES[3], 0); // bobinas trás
    
    Serial.println("Motores testados com sucesso.");
}

void corridaMotores()
{
    Serial.println("Correndo com os motores...");
    analogWrite(MOTORES[1], 255); // motor esquerdo frente
    analogWrite(MOTORES[2], 255); // motor direito frente
    delay(3000);               // Corre por 3 segundos
    Serial.println("Parando os motores...");
    analogWrite(MOTORES[1], 0);   // para motor esquerdo frente
    analogWrite(MOTORES[2], 0);   // para motor direito frente
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

void testMotores()
{
    // Testa os motores com base no estado do botão
    for (size_t i = 0; i < 3; i++)
    {
        if(i==0) {
            Serial.println("Iniciando motores...");
            initMotores();
            Serial.println("Motores inicializados.");
            delay(100);
            while (!debounceBotao()){}
        } else if(i==1) {
            Serial.println("Modo de corrida dos motores...");
            corridaMotores();
            delay(100);
            while (!debounceBotao()){}
        } else if(i==2) {
            Serial.println("Parando robo...");
            paradaRobo();
            while (!debounceBotao()){}
            delay(100);
        }
    }
}