#include <Arduino.h>
#include <pins.h>

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