#ifndef LEITOR_MATRIZ_HPP
#define LEITOR_MATRIZ_HPP


#include <string>
#include <vector>
#include <utility>

class leitorMatriz{
    private:
        int linhas, colunas;
        int fogoInicialX, fogoInicialY;
        std::vector<std::vector<char>> matriz;
    
    public:
        leitorMatriz();
        bool carregarArquivo(const std::string& caminhoArquivo, std::ofstream& arquivoSaida);
        int getLinhas() const;
        int getColunas() const;
        std::pair<int,int> getPosicaoInicial() const;
        std::vector<std::vector<char>>& getMatriz();        
        virtual ~leitorMatriz() = default;

};

#endif