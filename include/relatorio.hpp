#ifndef RELATORIO_HPP
#define RELATORIO_HPP

#include <vector>
#include <utility>
#include <string>
#include <fstream>

void gerarRelatorioFinal(
    const std::vector<std::vector<char>>& matriz,
    const std::vector<std::pair<int, int>>& caminhoPercorrido,
    int passos,
    bool chegouNaAgua,
    bool animalVivo,
    std::ofstream& arquivo
);

void salvarMatrizComCaminhoIteracao(
    const std::vector<std::vector<char>>& matriz,
    const std::vector<std::pair<int, int>>& caminhoPercorrido,
    std::ofstream& arquivo,
    int iteracao
);

#endif