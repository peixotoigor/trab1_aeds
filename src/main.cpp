#include "matriz_reader.hpp"
#include <iostream>

int main() {
    // Criar o objeto matrixReader
    matrixReader leitor;

    // Carregar o arquivo de entrada
    if (leitor.carregarArquivo("input.dat")) {
        std::cout << "Arquivo carregado com sucesso!" << std::endl;

        // Exibir as dimensões da matriz
        std::cout << "Dimensões da matriz: " 
                  << leitor.getComprimentoX() << " x " 
                  << leitor.getComprimentoY() << std::endl;

        // Exibir a posição inicial do incêndio
        auto posicaoInicial = leitor.getPosicaoInicial();
        std::cout << "Posição inicial do incêndio: (" 
                  << posicaoInicial.first << ", " 
                  << posicaoInicial.second << ")" << std::endl;

        // Exibir a matriz
        const auto& matriz = leitor.getMatriz();
        std::cout << "Matriz da floresta:" << std::endl;
        for (const auto& linha : matriz) {
            for (char celula : linha) {
                std::cout << celula << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cerr << "Erro ao carregar o arquivo!" << std::endl;
    }

    return 0;
}