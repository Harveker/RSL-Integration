#pragma once

//variáveis externas
// Strutura para maquina de estado ser chamada
struct MaquinasDeEstado
{
    Direcao direcaoAtual;
    void (*estadoDirecao)();
};

// Função direcionando o robo para frente
void frente();
// Função direcionando o robo para esquerda
void esquerda();
// Função direcionando o robo para esquerda fechada
void esquerdaCurta();
// Função direcionando o robo para direita
void direita();
// Função direcionando o robo para direita fechada
void direitaCurta();
// Função de parada através do sensor
bool paradaSensoriada(int valorSensores[]);
// Função de maquina de Estado para direcionar o robo de acordo com os sensores de linha
void transicaoDirecao(MaquinasDeEstado &me);
// Função de detecção para curva
bool limiteDeCurvaSensores();
// Função de escolha de direção baseado nos sensores
vS decisaoSensor (int valorSensores[]);
// Função para parar a direção do robô
void pararDirecao();

// Função para atualizar a direção do robô com base nos sensores
void atualizarDirecao();

// Função para configurar os pinos relacionados à direção
void configurarPinosDirecao();

// Função para obter o estado atual da direção
int obterEstadoDirecao();

// Função para definir o estado da direção
void definirEstadoDirecao(int estado);

// Função para calibrar a direção do robô
void calibrarDirecao();

// Função para resetar a direção do robô
void resetarDirecao();

// Função para testar a direção do robô
void testarDirecao();

// Função para imprimir o estado da direção do robô
void imprimirEstadoDirecao();

// Função para salvar a configuração da direção do robô
void salvarConfiguracaoDirecao();

// Função para carregar a configuração da direção do robô
void carregarConfiguracaoDirecao();

// Função para verificar se a direção do robô está correta
bool verificarDirecaoCorreta();

// Função para ajustar a sensibilidade da direção do robô
void ajustarSensibilidadeDirecao(int sensibilidade);

// Função para reiniciar a direção do robô
void reiniciarDirecao();

// Função para sincronizar a direção do robô com outros sistemas
void sincronizarDirecao();

// Função para diagnosticar problemas na direção do robô
void diagnosticarDirecao();

// Função para otimizar a direção do robô
void otimizarDirecao();

// Função para monitorar a direção do robô em tempo real
void monitorarDirecaoTempoReal();

// Função para configurar alertas relacionados à direção do robô
void configurarAlertasDirecao();

// Função para registrar dados da direção do robô
void registrarDadosDirecao();

// Função para analisar dados da direção do robô
void analisarDadosDirecao();