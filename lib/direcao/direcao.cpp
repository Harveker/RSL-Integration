#include <Arduino.h>
#include "config.h"
#include "direcao.h"
#include "leituraSensores.h"

struct MaquinasDeEstado{
    Direcao direcaoAtual;
    void(*estadoDirecao)();
};

void esquerda(){
    analogWrite(MOTORES[0],0);
    analogWrite(MOTORES[1],192);
    analogWrite(MOTORES[2],255);
    analogWrite(MOTORES[3],0);
}
void esquerdacurta(){
    analogWrite(MOTORES[0],0);
    analogWrite(MOTORES[1],128);
    analogWrite(MOTORES[2],255);
    analogWrite(MOTORES[3],0);
}
void direita(){
    analogWrite(MOTORES[0],0);
    analogWrite(MOTORES[1],255);
    analogWrite(MOTORES[2],192);
    analogWrite(MOTORES[3],0);
}
void direitacurta(){
    analogWrite(MOTORES[0],0);
    analogWrite(MOTORES[1],255);
    analogWrite(MOTORES[2],128);
    analogWrite(MOTORES[3],0);
}

void transicaoDirecao(MaquinasDeEstado &me){
    switch (me.direcaoAtual)
    {
    case ESQUERDA:
        while(valorSensores[3]>=200){
            
        } //sensor CD

        break;
    
    default:
        break;
    }
}
// Implementação das funções relacionadas à direção do robô
void ajustarDirecao(int (&direcao)[5]) {
    // Código para ajustar a direção do robô
    
}

