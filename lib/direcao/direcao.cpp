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
        if (valorSensores[i] > LIMITE_PARADA) // identifica quando os sensores passam por uma chegada.
        {
            return false;
        }
    }
    return true;
}

bool limiteDeCurvaSensores()        //nao sendo usado no momento
{
    for (size_t i = 0; i < NUM_SENSORES - 1; i++) //-1 pois o ultimo é o LDR
    {
        if (valorSensores[i] > LIMITE_PARADA)
        {
            return true;
        }
    }
    return false;
}

vS decisaoSensor(int valorSensores[])
{
    vS resultado = {};
    for (size_t i = 0; i < NUM_SENSORES - 1; i++) //-1 pois o ultimo é o LDR
    {
        if (valorSensores[i] < LIMITE_CURVA)
        {
            resultado.status[i] = valorSensores[i];
        } else {
            resultado.status[i] = -1;
        }
    // nenhum sensor detectou curva → inicializa todos com -1 ou valor alto
    }

    return resultado;
}

void transicaoDirecao(MaquinasDeEstado &me)
{
    lerSensores();  //avalia os sensores antes de tudo
    
    switch (me.direcaoAtual)
    {
    case FRENTE:
    {
        debugEstado("[STATE] FRENTE");
        
        me.estadoDirecao = frente;

        /* if (debounceBotao()) {
            delay(200);
            me.direcaoAtual = PARADO;
            me.estadoDirecao = paradaRobo;
            Serial.println("[TRANSITION] FRENTE → PARADO (botão pressionado)");
            return;
        } */

        lerSensores();
        if (paradaSensoriada(valorSensores)) // se detectar uma faixa para o robo
        {
            debugEstado("[TRANSITION] FRENTE → PARADO (faixa detectada)");
            me.direcaoAtual = PARADO;
            me.estadoDirecao = paradaRobo;
            return;
        }
        vS decisao = decisaoSensor(valorSensores);
        for (size_t i = 0; i < NUM_SENSORES - 1; i++)
        {
            if (decisao.status[i] <= LIMITE_CURVA && decisao.status[i] != -1) // limite para começar uma curva
            {
                debugEstado("entra nas decisões");
                switch (SENSORES[i])
                {
                case CE: // se interceptar o sensor central esquerdo
                {
                    debugEstado("[TRANSITION] FRENTE → ESQUERDA");
                    me.direcaoAtual = ESQUERDA;
                    me.estadoDirecao = esquerda;
                    return;
                }
                case LE: // se interceptar o sensor lateral esquerdo
                {
                    debugEstado("[TRANSITION] FRENTE → ESQUERDACURTA");
                    me.direcaoAtual = ESQUERDACURTA;
                    me.estadoDirecao = esquerdaCurta;
                    return;
                }
                case CD: // se interceptar o sensor central direito
                {
                    debugEstado("[TRANSITION] FRENTE → DIREITA");
                    me.direcaoAtual = DIREITA;
                    me.estadoDirecao = direita;
                    return;
                }
                case LD: // se interceptar o sensor lateral direito
                    debugEstado("[TRANSITION] FRENTE → DIREITACURTA");
                    me.direcaoAtual = DIREITACURTA;
                    me.estadoDirecao = direitaCurta;
                    return;
                }
            }
        }
        break;
    }
    case ESQUERDACURTA:
    {
        me.estadoDirecao = esquerdaCurta;
        lerSensores();
        debugEstado("[STATE] ESQUERDACURTA");
        if(valorSensores[1]<= LIMITE_CURVA) {
        debugEstado("[TRANSITION] ESQUERDACURTA → FRENTE");
        me.direcaoAtual = FRENTE;
        me.estadoDirecao = frente;
        }
        break;
    }
    case ESQUERDA:
    {
        me.estadoDirecao = esquerda;
        lerSensores();
        debugEstado("[STATE] ESQUERDA");
        if(valorSensores[2]<= LIMITE_CURVA) {
        debugEstado("[TRANSITION] ESQUERDA → FRENTE");
        me.direcaoAtual = FRENTE;
        me.estadoDirecao = frente;
        }
        break;
    }
    case DIREITA:
    {
        me.estadoDirecao = direita;
        lerSensores();
        debugEstado("[STATE] DIREITA");
        if(valorSensores[2]<= LIMITE_CURVA) {
        debugEstado("[TRANSITION] DIREITA → FRENTE");
        me.direcaoAtual = FRENTE;
        me.estadoDirecao = frente;
        }
        break;
    }
    case DIREITACURTA:
    {
        me.estadoDirecao = direitaCurta;
        lerSensores();
        debugEstado("[STATE] DIREITACURTA");
        if(valorSensores[3]<= LIMITE_CURVA) {
        debugEstado("[TRANSITION] DIREITACURTA → FRENTE");
        me.direcaoAtual = FRENTE;
        me.estadoDirecao = frente;
        }
        break;
    }
    case PARADO:
    {
        lerSensores();
        debugEstado("[STATE] PARADO — aguardando botão");
        me.estadoDirecao = paradaRobo;
        if (debounceBotao())
        {
            delay(200);
            Serial.println("[TRANSITION] PARADO → FRENTE (botão pressionado)");
            me.direcaoAtual = FRENTE;
            me.estadoDirecao = frente;
        }
        break;
    }
    default:
        lerSensores();
        debugEstado("[STATE] DEFAULT (fallback para PARADO)");
        me.direcaoAtual = PARADO;
        me.estadoDirecao = paradaRobo;
        break;
    }
}
// Implementação das funções relacionadas à direção do robô
