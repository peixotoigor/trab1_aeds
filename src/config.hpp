#ifndef CONFIG_HPP
#define CONFIG_HPP

const int MAX_ITERACOES =  10;
const bool VENTO_ATIVO = true;

enum direcoesVento {
    SEM_VENTO = 0,
    ESQUERDA = 1,
    DIREITA = 2,
    ACIMA = 4,
    ABAIXO = 8
};

const int VENTO_DIRECAO = SEM_VENTO; // ESQUERDA | DIREITA;

#endif //CONFIG_HPP
