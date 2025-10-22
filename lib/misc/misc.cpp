#include <Arduino.h>
#include "config.h"

// Implementação de funções diversas
bool debounceBotao() {
    static unsigned long lastPressTime = 0;
    const unsigned long debounceDelay = 50; // Tempo de debounce em milissegundos
    unsigned long currentTime = millis();

    if (digitalRead(BOTAO) == HIGH) {
        if (currentTime - lastPressTime > debounceDelay) {
            lastPressTime = currentTime;
            return true; // Botão pressionado com sucesso após debounce
        }
    }
    return false; // Botão não pressionado ou ainda em debounce
}

bool doublePressBotao() {
    static unsigned long firstPressTime = 0;
    const unsigned long doublePressDelay = 500; // Tempo máximo entre os dois pressionamentos

    if (digitalRead(BOTAO) == HIGH) {
        unsigned long currentTime = millis();
        if (firstPressTime == 0) {
            firstPressTime = currentTime; // Primeiro pressionamento
        } else {
            if (currentTime - firstPressTime <= doublePressDelay) {
                firstPressTime = 0; // Reset para o próximo duplo pressionamento
                return true; // Duplo pressionamento detectado
            } else {
                firstPressTime = currentTime; // Atualiza o tempo do primeiro pressionamento
            }
        }
    }
    return false; // Duplo pressionamento não detectado
}

bool holdPressBotao() {
    static unsigned long pressStartTime = 0;
    const unsigned long holdPressDelay = 1000; // Tempo mínimo para considerar como pressionamento longo

    if (digitalRead(BOTAO) == HIGH) {
        if (pressStartTime == 0) {
            pressStartTime = millis(); // Inicia o tempo do pressionamento
        } else {
            if (millis() - pressStartTime >= holdPressDelay) {
                pressStartTime = 0; // Reset para o próximo pressionamento longo
                return true; // Pressionamento longo detectado
            }
        }
    } else {
        pressStartTime = 0; // Reseta se o botão for solto
    }
    return false; // Pressionamento longo não detectado
}