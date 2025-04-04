#ifndef CONFIG_HPP
#define CONFIG_HPP

const int MAX_ITERACOES =  1000;
const bool VENTO_ATIVO = true;

enum direcoesVento {
    SEM_VENTO = 0,
    ESQUERDA = 1,
    DIREITA = 2,
    ACIMA = 4,
    ABAIXO = 8
};

const int VENTO_DIRECAO = SEM_VENTO;

#endif //CONFIG_HPP
