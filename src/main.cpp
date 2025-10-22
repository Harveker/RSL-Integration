#include <Arduino.h>
#include "config.h"
#include "misc.h"
#include "initStopRobo.h"
#include "leituraSensores.h"
#include "direcao.h"

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
MaquinasDeEstado estadoAtual = {PARADO, paradaRobo};  //inicializando maquina de estado parada

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  initConfig();
  configSensores();
  Serial.println("Configurações iniciais feitas.");
  Serial.println("Teste de motores pressione o botao em até 3 segundos para testar...");
  timer = millis() + 3000; // Espera 3 segundos antes de iniciar
  while(millis() < timer){
    if(debounceBotao()){
      Serial.println("Iniciando teste dos motores");
      testMotores();
      break;
    }
  }
  Serial.println("Teste de motores cancelado, seguindo...");
  delay(10);
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
  delay(10);
  Serial.println("Modo competição habilitado...");
  
  // Outras inicializações podem ser adicionadas aqui

}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("Lendo sensores");
  lerSensores(); //função void que atualiza os sensores de linha e ldr
  while(doublePressBotao()){}
  //vamos começar com uma ideia binária do robo
  //queremos que este, vire na direção da linha apenas (o quanto será uma questão matematica que veremos posteriormente)
  transicaoDirecao(estadoAtual);
}
