#ifndef MELHOR_MOVIMENTO_HPP
#define MELHOR_MOVIMENT_HPP
#include <vector>

std::pair<int, int> buscarMelhorMovimento(
    const std::vector<std::vector<char>>& matriz,
    int posAnimalX,
    int posAnimalY,
    int linhas,
    int colunas,
    const std::vector<std::pair<int, int>>& caminhoPercorrido
);
#endif