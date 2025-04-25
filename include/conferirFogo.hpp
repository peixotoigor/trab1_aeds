#ifndef CONFERIR_FOGO_HPP
#define CONFERIR_FOGO_HPP

#include <vector>
#include <iostream>

void verificarFogoSobreAnimal(std::vector<std::vector<char>>& matriz, 
    int& posAnimalX, 
    int& posAnimalY, 
    int linhas, 
    int colunas,
    bool& animalVivo,
    std::vector<std::pair<int, int>>& caminhoPercorrido );

#endif