#include <Arduino.h>
#include <pins.h>
#include "config.h"
#include "misc.h"
#include "initStopRobo.h"

// Definição de pinos:

/*
Para a produção de todo programa, devemos pensar primeiro em sua estrutura básica.
O que queremos que o programa faça? Quais funções ele deve ter? Quais variáveis serão necessárias?
Depois de planejar a estrutura, podemos começar a escrever o código.
No nosso caso, queremos criar um programa em que um robo segue linhas, usando sensores para detectar as linhas e motores para movimentar o robo.
Primeiro, precisamos definir as funções que o programa terá.
Por exemplo, uma função para ler os sensores, outra para controlar os motores, e talvez uma função principal que coordena tudo.
Depois de definir as funções, podemos declarar as variáveis necessárias.
Por exemplo, variáveis para armazenar os valores dos sensores, a velocidade dos motores, etc.
Depois de planejar a estrutura do programa, podemos começar a escrever o código.
*/

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  initConfig();
  // Outras inicializações podem ser adicionadas aqui
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (debounceBotao()){
    valorButao++;
  }
  switch (valorButao){
    case 1:
    Serial.println("Iniciando motores...");
    initMotores();
    Serial.println("Motores inicializados.");
    break;
    case 2:
    Serial.println("Modo de corrida dos motores...");
    corridaMotores();
    break;
    case 3:
    Serial.println("Parando robo...");
    paradaRobo();
    break;
    default:
    break;
  }
}
