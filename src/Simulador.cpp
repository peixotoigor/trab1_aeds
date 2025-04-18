#include "config.hpp"
#include "leitorMatriz.hpp"
#include "numAleatorio.hpp"
#include "umidade.hpp"
#include "conferirFogo.hpp"
#include "melhorMovimento.hpp"
#include "propagacaoFogo.hpp"
#include "relatorio.hpp"

#include <string>	
#include <queue>
#include <iostream>
#include <fstream>
#include <vector>

// Verifica se toda a área foi consumida pelo fogo (não há mais '1' ou '2')
bool areaConsumidaPeloFogo(const std::vector<std::vector<char>>& matriz) {
    for (const auto& linha : matriz) {
        for (char celula : linha) {
           if (celula == '2'|| celula=='1') {
           //if (celula == '2') {
                return false; // Ainda há fogo
            }
        }
    }
    return true; // Tudo foi queimado ou virou outro estado
}

void executarSimulacao() {
    // Leitura do arquivo
    leitorMatriz leitor;
    std::string caminhoArquivo = "../data/input.dat";
    std::ofstream arquivoSaida("../data/log.dat");
    leitor.carregarArquivo(caminhoArquivo, arquivoSaida);
    
    // Obter dados
    int linhas = leitor.getLinhas();
    int colunas = leitor.getColunas();
    std::vector<std::vector<char>>& matrizOriginal = leitor.getMatriz();
    auto posicaoInicial = leitor.getPosicaoInicial();
    int fogoInicialX = posicaoInicial.first;
    int fogoInicialY = posicaoInicial.second;

    // Inicializa fila do fogo e marca primeiro foco
    std::queue<std::pair<int, int>> filaFogo;
    filaFogo.push({fogoInicialX, fogoInicialY});
    matrizOriginal[fogoInicialX][fogoInicialY] = '2';

    // Posição aleatória do animal
    //int posAnimalX = 0;
    //int posAnimalY = 0;
    int posAnimalX = numeroAleatorio(0, linhas - 1);
    int posAnimalY = numeroAleatorio(0, colunas - 1);
    std::vector<std::pair<int, int>> caminhoPercorrido;
    caminhoPercorrido.push_back({posAnimalX, posAnimalY});

    // Variáveis de controle
    int contadorPermanencia = 0;
    int contadorPassos = 0;
    int iteracaoAtual = 0;
    bool animalVivo = true;
    bool chegouNaAgua = false;
    bool areaDisponivel = true;

    std::ofstream arquivoSaidaIter("../data/saida.dat");

    // Loop principal da simulação
    while (iteracaoAtual < MAX_ITERACOES && animalVivo && areaDisponivel){
        
        salvarMatrizComCaminhoIteracao(matrizOriginal, 
            caminhoPercorrido,
            arquivoSaidaIter, 
            iteracaoAtual);

        // Caso o animal alcance a água
        if (matrizOriginal[posAnimalX][posAnimalY] == '4') {
            aplicarUmidade(matrizOriginal, posAnimalX, posAnimalY, linhas, colunas);
            chegouNaAgua = true;
        }

        // Regra de permanência em local seguro
        if (matrizOriginal[posAnimalX][posAnimalY] == '0' && contadorPermanencia < MAX_PERMANENCIA) {
            contadorPermanencia++;
        } else {
            // Movimentação do animal
            auto destino = buscarMelhorMovimento(matrizOriginal, posAnimalX, posAnimalY, linhas, colunas, caminhoPercorrido);
            if (destino.first != -1 && destino.second != -1) {
                posAnimalX = destino.first;
                posAnimalY = destino.second;
                caminhoPercorrido.push_back(destino);
                contadorPassos++;
                contadorPermanencia = 0;
            }
        }

        // Propagação do fogo (por uma iteração)
        executarFogoIteracao(matrizOriginal, linhas, colunas, filaFogo);


        // Verifica se o animal foi atingido pelo fogo
        verificarFogoSobreAnimal(matrizOriginal, posAnimalX, posAnimalY, linhas, colunas, animalVivo);
        if (!animalVivo) {
            break;
        }
        
        // Verifica se toda a área foi consumida pelo fogo
        areaDisponivel = !areaConsumidaPeloFogo(matrizOriginal);
        if (!areaDisponivel) {
            break; // Encerra a simulação, pois não há mais fogo para propagar
        }
        
        iteracaoAtual++;
    }
   

    // Gera relatório final (se desejar)
    salvarMatrizComCaminhoIteracao(matrizOriginal, 
        caminhoPercorrido,
        arquivoSaidaIter, 
        iteracaoAtual);
    gerarRelatorioFinal(matrizOriginal, caminhoPercorrido, contadorPassos, chegouNaAgua, animalVivo, arquivoSaidaIter); 
    arquivoSaidaIter.close();
    arquivoSaida.close();
}

