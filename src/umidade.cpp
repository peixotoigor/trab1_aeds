#include "umidade.hpp"
#include "config.hpp"

void aplicarUmidade(std::vector<std::vector<char>>& matriz, int posAnimalX, int posAnimalY, int linhas, int colunas) {
    // Atualiza a célula de água para estado seguro
    matriz[posAnimalX][posAnimalY] = '0';

    for (const auto& direcao : DIRECOES_ORTOGONAIS) {
        int dx = posAnimalX + direcao.first;
        int dy = posAnimalY + direcao.second;

        if (dx >= 0 && dx < linhas && dy >= 0 && dy < colunas) {
            if (matriz[dx][dy] == '2') {
                // Se estiver pegando fogo, volta a ser árvore
                matriz[dx][dy] = '1';
            } else if (matriz[dx][dy] != '4') {
                // Se não for água, aplica umidade (torna árvore saudável)
                matriz[dx][dy] = '1';
            }
        }
    }
}