#include "matriz_reader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor
matrixReader::matrixReader()
    : comprimentoX(0), comprimentoY(0), posicaoX_inicial(0), posicaoY_inicial(0), matriz() {}
// Leitura arquivo
bool matrixReader::carregarArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }

    // Obtenção da primeira linha
    std::string linha;
    if (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);
        if (!(ss >> comprimentoX >> comprimentoY >> posicaoX_inicial >> posicaoY_inicial)) {
            std::cerr << "Erro ao processar a primeira linha do arquivo!" << std::endl;
            return false;
        }
    } else {
        std::cerr << "Erro ao fazer leitura da primeira linha do arquivo!" << std::endl;
        return false;
    }

    // Limpar e redimensionar a matriz
    matriz.clear();
    matriz.resize(comprimentoY);
    for (int i = 0; i < comprimentoY; i++) {
        matriz[i].resize(comprimentoX);
    }

    // Leitura das linhas da matriz com validação
    for (int i = 0; i < comprimentoY; i++) {
        if (!std::getline(arquivo, linha)) {
            std::cerr << "Erro ao ler a linha: " << i + 1 << " da matriz!" << std::endl;
            return false;
        }
        std::istringstream ss(linha);
        for (int j = 0; j < comprimentoX; j++) {
            if (!(ss >> matriz[i][j])) {
                std::cerr << "Erro ao ler o valor na posição (" << i << ", " << j << ")!" << std::endl;
                return false;
            }
        }
    }

    return true;
}

int matrixReader::getComprimentoX() const {
    return comprimentoX;
}

int matrixReader::getComprimentoY() const {
    return comprimentoY;
}

std::pair<int, int> matrixReader::getPosicaoInicial() const {
    return {posicaoX_inicial, posicaoY_inicial};
}

const std::vector<std::vector<char>>& matrixReader::getMatriz() const {
    return matriz;
}