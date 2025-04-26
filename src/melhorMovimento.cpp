#include "melhorMovimento.hpp"
#include "config.hpp"

std::pair<int, int> buscarMelhorMovimento(
    const std::vector<std::vector<char>>& matriz,
    int posAnimalX,
    int posAnimalY,
    int linhas,
    int colunas,
    const std::vector<std::pair<int, int>>& caminhoPercorrido
) {
    // Segunda chance: se o animal está em fogo, tenta fugir imediatamente
    if (matriz[posAnimalX][posAnimalY] == '2') {
        for (const auto& dir : DIRECOES_ORTOGONAIS) {
            int nx = posAnimalX + dir.first;
            int ny = posAnimalY + dir.second;
            if (nx >= 0 && nx < linhas && ny >= 0 && ny < colunas) {
                // Não pode fugir para fogo nem para tronco queimado
                if (matriz[nx][ny] != '2' && matriz[nx][ny] != '3') {
                    return {nx, ny}; // Fuga imediata
                }
            }
        }
        return {-1, -1}; // Cercado pelo fogo ou queimado, não há fuga
    }

    int melhorPrioridade = 1000000;
    std::pair<int, int> melhorDestino = {-1, -1};

    // Primeiro, tenta encontrar movimento para posição não visitada
    for (const auto& dir : DIRECOES_ORTOGONAIS) {
        int nx = posAnimalX + dir.first;
        int ny = posAnimalY + dir.second;
        if (nx >= 0 && nx < linhas && ny >= 0 && ny < colunas) {
            bool jaVisitado = false;
            for (const auto& pos : caminhoPercorrido) {
                if (pos.first == nx && pos.second == ny) {
                    jaVisitado = true;
                    break;
                }
            }
            if (jaVisitado) continue;

            char celula = matriz[nx][ny];
            // Não pode ir para fogo nem para queimado
            if (celula == '2' || celula == '3') continue;

            int prioridade;
            if (celula == '4') prioridade = 1;
            else if (celula == '0') prioridade = 2;
            else if (celula == '1') prioridade = 3;
            else continue;

            if (prioridade < melhorPrioridade) {
                melhorPrioridade = prioridade;
                melhorDestino = {nx, ny};
            }
        }
    }

    // Se não encontrou posição não visitada, permite retornar para já visitada (última prioridade)
    if (melhorDestino.first == -1 && melhorDestino.second == -1) {
        melhorPrioridade = 1000000;
        for (const auto& dir : DIRECOES_ORTOGONAIS) {
            int nx = posAnimalX + dir.first;
            int ny = posAnimalY + dir.second;
            if (nx >= 0 && nx < linhas && ny >= 0 && ny < colunas) {
                char celula = matriz[nx][ny];
                // Não pode ir para fogo nem para queimado
                if (celula == '2' || celula == '3') continue;

                int prioridade;
                if (celula == '4') prioridade = 1;
                else if (celula == '0') prioridade = 2;
                else if (celula == '1') prioridade = 3;
                else continue;

                if (prioridade < melhorPrioridade) {
                    melhorPrioridade = prioridade;
                    melhorDestino = {nx, ny};
                }
            }
        }
    }

    return melhorDestino;
}