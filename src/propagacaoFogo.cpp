#include "propagacaoFogo.hpp"
#include "config.hpp"
#include <queue>
#include <iostream>


// Função chamada uma vez por iteração
void executarFogoIteracao(
    std::vector<std::vector<char>>& matriz,
    int linhas,
    int colunas,
    std::queue<std::pair<int, int>>& filaFogo
){
    int tamanhoFila = filaFogo.size();

    // Nada para propagar
    if (tamanhoFila == 0) return;

    for (int i = 0; i < tamanhoFila; ++i) {
        auto [x, y] = filaFogo.front();
        filaFogo.pop();

        // Queima a célula atual ('2' vira '3')
        matriz[x][y] = '3';

        // Tenta propagar para vizinhos
        for (DIRECOES direcao : VENTO_DIRECOES) {
            int dx = 0, dy = 0;

            switch (direcao) {
                case ACIMA: dx = -1; break;
                case ABAIXO: dx = 1; break;
                case ESQUERDA: dy = -1; break;
                case DIREITA: dy = 1; break;
                default: break;
            }

            int novoX = x + dx;
            int novoY = y + dy;

            if (novoX >= 0 && novoX < linhas && novoY >= 0 && novoY < colunas) {
                if (matriz[novoX][novoY] == '1') {
                    matriz[novoX][novoY] = '2';  // pega fogo
                    filaFogo.push({novoX, novoY});
                }
            }
        }
    }
}
