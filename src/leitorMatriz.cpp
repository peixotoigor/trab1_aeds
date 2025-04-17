#include "leitorMatriz.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor
leitorMatriz::leitorMatriz()
    : linhas(0), colunas(0), fogoInicialX(0), fogoInicialY(0), matriz() {}
    
// Leitura do arquivo
bool leitorMatriz::carregarArquivo(const std::string& caminhoArquivo, std::ofstream& arquivoSaida) {

    std::ifstream arquivo(caminhoArquivo);
    if (!arquivo.is_open()) {
        arquivoSaida << "Erro ao abrir o arquivo: " << caminhoArquivo << std::endl;
        return false;
    }

    // Obtenção da primeira linha
    std::string linha;
    if (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);
        if (!(ss >> linhas >> colunas >> fogoInicialX >> fogoInicialY)) {
            arquivoSaida << "Erro ao processar a primeira linha do arquivo!" << std::endl;
            return false;
        }
    } else {
        arquivoSaida << "Erro ao fazer leitura da primeira linha do arquivo!" << std::endl;
        return false;
    }

    // Limpar e redimensionar a matriz
    matriz.clear();
    matriz.resize(linhas);
    for (int i = 0; i < linhas; i++) {
        matriz[i].resize(colunas);
    }

    // Leitura das linhas da matriz com validação
    for (int i = 0; i < linhas; i++) {
        if (!std::getline(arquivo, linha)) {
            arquivoSaida << "Erro ao ler a linha: " << i + 1 << " da matriz!" << std::endl;
            return false;
        }
        std::istringstream ss(linha);
        for (int j = 0; j < colunas; j++) {
            if (!(ss >> matriz[i][j])) {
                arquivoSaida << "Erro ao ler o valor na posição (" << i << ", " << j << ")!" << std::endl;
                return false;
            }
        }
    }

    return true;
}

// Métodos para acessar os dados
int leitorMatriz::getLinhas() const {
    return linhas;
}

int leitorMatriz::getColunas() const {
    return colunas;
}

std::pair<int, int> leitorMatriz::getPosicaoInicial() const {
    return {fogoInicialX, fogoInicialY};
}

std::vector<std::vector<char>>& leitorMatriz::getMatriz() {
    return matriz;
}