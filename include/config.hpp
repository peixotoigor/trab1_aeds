#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <vector>
#include <utility>

// Número máximo de iterações
const int MAX_ITERACOES = 100;

// Número máximo de permanência
const int MAX_PERMANENCIA = 3;

// Ativar ou desativar o ventgo
const bool VENTO_ATIVO = false;

// Enum para identificar as direções do vento
enum DIRECOES {
    SEM_VENTO,
    ESQUERDA,
    DIREITA,
    ACIMA,
    ABAIXO
};

// Variável para definir as direções do vento (pode conter várias direções)
const std::vector<DIRECOES> VENTO_DIRECOES = VENTO_ATIVO 
    ? std::vector<DIRECOES>{ABAIXO, DIREITA} // Direções configuradas quando o vento está ativo
    : std::vector<DIRECOES>{ESQUERDA, DIREITA, ACIMA, ABAIXO}; // Todas as direções quando SEM_VENTO

// Matriz de direções para cada tipo de vento
const std::vector<std::pair<int, int>> DIRECOES_VENTO = {
    {-1, 0}, // Cima
    {1, 0},  // Baixo
    {0, -1}, // Esquerda
    {0, 1}   // Direita
};

const std::vector<std::pair<int, int>> DIRECOES_ORTOGONAIS = {
    {-1, 0}, // Cima
    {1, 0},  // Baixo
    {0, -1}, // Esquerda
    {0, 1}   // Direita
};
#endif // CONFIG_HPP