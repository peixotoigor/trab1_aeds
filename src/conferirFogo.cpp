#include "conferirFogo.hpp"
#include "config.hpp"

void verificarFogoSobreAnimal(std::vector<std::vector<char>>& matriz, 
    int& posAnimalX, 
    int& posAnimalY, 
    int linhas, 
    int colunas,
    bool& animalVivo){
    
    if(matriz[posAnimalX][posAnimalY] != '2'){
        return; //Animal não foi atingido
    }

    for (const auto& direcoes : DIRECOES_ORTOGONAIS){
        int dx = posAnimalX + direcoes.first;
        int dy = posAnimalY + direcoes.second;
        if (dx >= 0 && dx < linhas && dy >= 0 && dy < colunas) {
            char celula = matriz[dx][dy];
            if (celula == '0' || celula == '1' || celula == '4') {
                posAnimalX = dx;
                posAnimalY = dy;
                return;
            }
        }

    }
    animalVivo = false;
}
