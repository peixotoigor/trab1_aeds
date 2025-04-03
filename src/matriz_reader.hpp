#ifndef MATRIZ_READER_HPP
#define MATRIZ_READER_HPP

#include <string>
#include <vector>
#include <utility>

class matrixReader{
    private:
        int comprimentoX, comprimentoY;
        int posicaoX_inicial, posicaoY_inicial;
        std::vector<std::vector<char>> matriz;
    
    public:
        matrixReader();
        bool carregarArquivo(const std::string& nomeArquivo); 
        int getComprimentoX() const;
        int getComprimentoY() const;
        std::pair<int,int> getPosicaoInicial() const;
        const std::vector<std::vector<char>>& getMatriz() const;        
        virtual ~matrixReader() = default;

};

#endif