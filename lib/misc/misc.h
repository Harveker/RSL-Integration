#pragma once

// Declaração de funções diversas

// Função para debouncing do botão
bool debounceBotao();

// Função para detectar duplo pressionamento do botão
bool doublePressBotao();

// Função para detectar pressionamento longo do botão
bool holdPressBotao();

#ifdef DEBUG
extern unsigned long timer;
#endif

// text-only
inline void debugEstado(const char *msg) {
#ifdef DEBUG
    static unsigned long ultimaImpressao = 0;
    unsigned long agora = millis();
    if (agora - ultimaImpressao >= 500UL) {
        Serial.println(msg);
        ultimaImpressao = agora;
    }
#endif
}

// templated version
template<typename T>
inline void debugEstado(const char *msg, T value) {
#ifdef DEBUG
    static unsigned long ultimaImpressao = 0;
    unsigned long agora = millis();
    if (agora - ultimaImpressao >= 500UL) {
        Serial.print(msg);
        Serial.print(": ");
        Serial.println(value);
        ultimaImpressao = agora;
    }
#endif
}