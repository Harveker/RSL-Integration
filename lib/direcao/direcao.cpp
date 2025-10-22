#include <Arduino.h>
#include "config.h"
#include "direcao.h"
#include "leituraSensores.h"
#include "initStopRobo.h"
#include "misc.h"


/*🧠 Structural Suggestion (for future maintainability)

You can replace the long motor-setting functions with a single parametric one:

void moverMotores(int m0, int m1, int m2, int m3) {
    analogWrite(MOTORES[0], m0);
    analogWrite(MOTORES[1], m1);
    analogWrite(MOTORES[2], m2);
    analogWrite(MOTORES[3], m3);
}

Then define:

void frente()        { moverMotores(0, 255, 255, 0); }
void esquerda()      { moverMotores(0, 192, 255, 0); }
void esquerdaCurta() { moverMotores(0, 128, 255, 0); }
void direita()       { moverMotores(0, 255, 192, 0); }
void direitaCurta()  { moverMotores(0, 255, 128, 0); }


That way, if you ever change the motor pin order, you only update one place.
*/

void frente()
{
    analogWrite(MOTORES[0], 0);
    analogWrite(MOTORES[1], 255);
    analogWrite(MOTORES[2], 255);
    analogWrite(MOTORES[3], 0);
}

void esquerda()
{
    analogWrite(MOTORES[0], 0);
    analogWrite(MOTORES[1], 192);
    analogWrite(MOTORES[2], 255);
    analogWrite(MOTORES[3], 0);
}
void esquerdaCurta()
{
    analogWrite(MOTORES[0], 0);
    analogWrite(MOTORES[1], 128);
    analogWrite(MOTORES[2], 255);
    analogWrite(MOTORES[3], 0);
}
void direita()
{
    analogWrite(MOTORES[0], 0);
    analogWrite(MOTORES[1], 255);
    analogWrite(MOTORES[2], 192);
    analogWrite(MOTORES[3], 0);
}
void direitaCurta()
{
    analogWrite(MOTORES[0], 0);
    analogWrite(MOTORES[1], 255);
    analogWrite(MOTORES[2], 128);
    analogWrite(MOTORES[3], 0);
}

bool paradaSensoriada(int valorSensores[])
{
    for (size_t i = 0; i < NUM_SENSORES - 1; i++) //-1 pois o ultimo é o LDR
    {
        if (valorSensores[i] > 200) // identifica quando os sensores passam por uma chegada.
        {
            return false;
        }
    }
    return true;
}

bool limiteDeCurvaSensores()
{
    for (size_t i = 0; i < NUM_SENSORES - 1; i++) //-1 pois o ultimo é o LDR
    {
        if (valorSensores[i] <= 200)
        {
            return true;
        }
    }
    return false;
}

vS decisaoSensor(int valorSensores[])
{
    vS resultado;
    for (size_t i = 0; i < NUM_SENSORES - 1; i++) //-1 pois o ultimo é o LDR
    {
        if (valorSensores[i] < 200)
        {
            resultado.status[i] = valorSensores[i];
            return resultado;
        }
    }
    for (size_t i = 0; i < NUM_SENSORES; i++) // inicialização se nenhum sensor for para curva
    {
        resultado.status[i] = -1;
    }
    return resultado;
}

void transicaoDirecao(MaquinasDeEstado &me)
{
    switch (me.direcaoAtual)
    {
    case FRENTE: {
        while (limiteDeCurvaSensores()) // continuará reto até uma linha interceptar os sensores centrais
        {
            lerSensores();     // atualiza valores
        }
        vS decisao = decisaoSensor(valorSensores);
        if (paradaSensoriada(valorSensores)) // se detectar uma faixa para o robo
        {
            me.direcaoAtual = PARADO;
            me.estadoDirecao = paradaRobo;
        }
        for (size_t i = 0; i < NUM_SENSORES - 1; i++)
        {
            if (decisao.status[i] <= 200) // limite para começar uma curva
            {
                switch (SENSORES[i])
                {
                case CE: // se interceptar o sensor central esquerdo
                {
                    me.direcaoAtual = ESQUERDA;
                    me.estadoDirecao = esquerda;
                    break;
                }
                case LE: // se interceptar o sensor lateral esquerdo
                {
                    me.direcaoAtual = ESQUERDACURTA;
                    me.estadoDirecao = esquerdaCurta;
                    break;
                }
                case CD: // se interceptar o sensor central direito
                {
                    me.direcaoAtual = DIREITA;
                    me.estadoDirecao = direita;
                    break;
                }
                case LD: // se interceptar o sensor lateral direito
                    me.direcaoAtual = DIREITACURTA;
                    me.estadoDirecao = direitaCurta;
                    break;

                default:
                    break;
                }
            }
        }
        break;
    }
    case ESQUERDACURTA:
    {
        while (valorSensores[0] <= 200)
        {
        }
        me.direcaoAtual = FRENTE;
        me.estadoDirecao = frente;
        break;
    }
    case ESQUERDA:
    {
        while (valorSensores[1] <= 200)
        {
        } // sensor CE
        me.direcaoAtual = FRENTE;
        me.estadoDirecao = frente;
        break;
    }
    case DIREITA:
    {
        while (valorSensores[2] <= 200)
        {
        }
        me.direcaoAtual = FRENTE;
        me.estadoDirecao = frente;
        break;
    }
    case DIREITACURTA:
    {
        while (valorSensores[3] <= 200)
        {
        }
        me.direcaoAtual = FRENTE;
        me.estadoDirecao = frente;
        break;
    }
    case PARADO:
    {
        while (!holdPressBotao())
        {
            delay(10); 
        }
        me.direcaoAtual = FRENTE;
        me.estadoDirecao = frente;
        break;
    }
    default:
        me.direcaoAtual = PARADO;
        me.estadoDirecao = paradaRobo;
        break;
    }
}
// Implementação das funções relacionadas à direção do robô
