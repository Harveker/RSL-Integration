#include <Arduino.h>
#include "config.h"

bool debounceBotao()
{
    static unsigned long lastPressTime = 0;
    const unsigned long debounceDelay = 50;
    unsigned long currentTime = millis();
    if (digitalRead(BOTAO) == HIGH)
    {
        if (currentTime - lastPressTime > debounceDelay)
        {
            lastPressTime = currentTime;
            return true;
        }
    }
    return false;
}
bool doublePressBotao()
{
    static unsigned long firstPressTime = 0;
    const unsigned long doublePressDelay = 500;
    if (digitalRead(BOTAO) == HIGH)
    {
        unsigned long currentTime = millis();
        if (firstPressTime == 0)
        {
            firstPressTime = currentTime;
        }
        else
        {
            if (currentTime - firstPressTime <= doublePressDelay)
            {
                firstPressTime = 0;
                return true;
            }
            else
            {
                firstPressTime = currentTime;
            }
        }
    }
    return false;
}
bool holdPressBotao()
{
    static unsigned long pressStartTime = 0;
    const unsigned long holdPressDelay = 1000;
    if (digitalRead(BOTAO) == HIGH)
    {
        if (pressStartTime == 0)
        {
            pressStartTime = millis();
        }
        else
        {
            if (millis() - pressStartTime >= holdPressDelay)
            {
                pressStartTime = 0;
                return true;
            }
        }
    }
    else
    {
        pressStartTime = 0;
    }
    return false;
}