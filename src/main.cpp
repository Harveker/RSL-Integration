#include <Arduino.h>
#include "config.h"
#include "misc.h"
#include "initStopRobo.h"
#include "leituraSensores.h"

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
  Serial.begin(9600);
  initConfig();
  configSensores();
  Serial.println("Configurações iniciais feitas.");
  Serial.println("Iniciando teste dos motores...");
  while(!debounceBotao()){
  }  
  Serial.println("Botão pressionado, iniciando sequência...");
  testMotores();
  Serial.println("Iniciando em 3 segundos...");
  Serial.println("pressione o botão para modo debug");
  timer = millis() + 3000; // Espera 3 segundos antes de iniciar
  while(millis() < timer){
    if(debounceBotao()){
      Serial.println("Modo debug ativado.");
      // Aqui podemos adicionar código para o modo debug
      break;
    }
  }
  Serial.println("Iniciando corrida dos motores...");
  // Outras inicializações podem ser adicionadas aqui



}

void loop()
{
  // put your main code here, to run repeatedly:
  lerSensores();
}
