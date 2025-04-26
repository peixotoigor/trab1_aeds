#include "relatorio.hpp"
#include <iostream>
#include <fstream>

void gerarRelatorioFinal(
    const std::vector<std::vector<char>>& matriz,
    const std::vector<std::pair<int, int>>& caminhoPercorrido,
    int passos,
    bool chegouNaAgua,
    bool animalVivo,
    int iteracao,
    std::ofstream& arquivo
) {
    std::cout << "\n--- MATRIZ FINAL ---" << std::endl;
    for (const auto& linha : matriz) {
        for (char celula : linha) {
            if (celula == '2') {
                std::cout << "🔥 ";
            } else if (celula == '4') {
                std::cout << "💧 ";
            } else if (celula == '1') {
                std::cout << "🌳 ";
            } else if (celula == '0') {
                std::cout << "⬜ ";
            } else {
                std::cout << celula << " ";
            }
        }
        std::cout << std::endl;
    }

    arquivo << "\nCaminho percorrido pelo animal:" << std::endl;
    for (const auto& pos : caminhoPercorrido) {
        arquivo << "(" << pos.first << "," << pos.second << ")";
    }
    arquivo << std::endl;

    arquivo << "Passos percorridos: " << passos << std::endl;

    if (chegouNaAgua) {
        arquivo << "Animal sobreviveu (chegou à água)" << std::endl;
    } else if (!animalVivo) {
        arquivo << "Animal morreu no incêndio" << std::endl;
    } else {
        arquivo << "Animal sobreviveu até o fim" << std::endl;
    }
}

void salvarMatrizComCaminhoIteracao(
    const std::vector<std::vector<char>>& matriz,
    const std::vector<std::pair<int, int>>& caminhoPercorrido,
    std::ofstream& arquivo,
    int iteracao
) {
    std::vector<std::vector<char>> matrizCopia = matriz;
    for (const auto& pos : caminhoPercorrido) {
        int x = pos.first;
        int y = pos.second;
        matrizCopia[x][y] = '*';
    }

    arquivo << "--- Iteracao " << iteracao+1 << " ---\n";
    arquivo << " --- Posição Animal "<< " ---\n";

    for (const auto& linha : matrizCopia) {
        for (char celula : linha) {
            if (celula == '2') {
                arquivo << "🔥 ";
            } else if (celula == '4') {
                arquivo << "💧 ";
            } else if (celula == '1') {
                arquivo << "🌳 ";
            } else if (celula == '0') {
                arquivo << "⬜ ";
            } else if (celula == '3') {
                arquivo << "🪵 ";
            } else if (celula == '*') {
                arquivo << "🐒 ";
            } else {
                arquivo << celula << " ";
            }
        }
        arquivo << "\n";
    }
    arquivo << "\n";
    arquivo << " --- Posição Fogo "<< " ---\n";
    for (const auto& linha : matriz) {
        for (char celula : linha) {
            if (celula == '2') {
                arquivo << "🔥 ";
            } else if (celula == '4') {
                arquivo << "💧 ";
            } else if (celula == '1') {
                arquivo << "🌳 ";
            } else if (celula == '0') {
                arquivo << "⬜ ";
            } else if (celula == '3') {
                arquivo << "🪵 ";
            } else {
                arquivo << celula << " ";
            }
        }
        arquivo << "\n";
    }
    arquivo << "\n";
}