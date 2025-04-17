#ifndef PROPAGACAO_FOGO_HPP
#define PROPAGACAO_FOGO_HPP
#include <vector>
#include <iostream>
#include <queue>

void executarFogoIteracao(std::vector<std::vector<char>>& matriz,  int linhas, int colunas, std::queue<std::pair<int, int>>& filaFogo
);

#endif