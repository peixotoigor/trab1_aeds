## Caso 2: Sem presença de vento

Para o caso de teste utilizando a configuração sem vento, isto é, o fogo se propaga por todas as direções ortogonais, foram utilizados os seguintes parâmetros que podem ser modificados no arquivo [config.hpp](include/config.hpp).
```cpp
// Número máximo de iterações
const int MAX_ITERACOES = 100;

// Número máximo de permanência
const int MAX_PERMANENCIA = 3;

// Número máximo de vidas
const int MAX_VIDAS = 1;

// Ativar ou desativar o ventgo
const bool VENTO_ATIVO = false;
```
A matriz utilizada, no tamanho 10x10, gerada através do script [geradorMatriz.pu](data/geradorMatriz.py) foi configurada para que 70% da aréa fosse composta por árvores saudáveis, 20% por espaços vazios e 10% contendo água:
```pyhton
num_ones = int(total_cells * 0.7)  # arvores saudaveis
num_zeros = int(total_cells * 0.2) # espaços vazios
num_fours = total_cells - num_ones - num_zeros  # agua
```
No qual resultou na matriz:
```
10 10 6 1
1 1 1 0 1 0 1 1 4 1
4 1 1 1 1 1 0 1 4 4
1 1 1 1 1 1 1 0 1 1
1 1 1 1 0 1 1 0 4 1
1 1 1 1 1 0 1 1 4 1
0 0 1 0 1 1 0 1 1 1
1 2 1 0 1 1 0 0 1 1
1 1 1 1 0 1 1 4 1 1
1 1 0 1 1 1 4 4 1 0
1 1 0 0 1 0 4 1 1 1
```
Assim , posição inicial para o fogo foi linha 6 e coluna 1 (lembrando que o indice começa em 0).
Para facilitar a visualização, definiu-se as seguintes figuras para representar cada estado:

    * Espaço vazio (0): ⬜
    * Árvore saúdavel (1): 🌳 
    * Incêndio (2): 🔥
    * Árvore saúdavel (3): 🪵
    * Água (4): 💧

A cposição inicial do agente, representado por 🐒, foi estabelecido aleatoriamente, e encontrou-se na linha 3 e coluna 7. O ambiente de simulação inical (iteração 1) pode ser visualizado abaixo:
```
🌳 🌳 🌳 ⬜ 🌳 ⬜ 🌳 🌳 💧 🌳 
💧 🌳 🌳 🌳 🌳 🌳 ⬜ 🌳 💧 💧 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 ⬜ 🌳 🌳 
🌳 🌳 🌳 🌳 ⬜ 🌳 🌳 🐒 💧 🌳 
🌳 🌳 🌳 🌳 🌳 ⬜ 🌳 🌳 💧 🌳 
⬜ ⬜ 🌳 ⬜ 🌳 🌳 ⬜ 🌳 🌳 🌳 
🌳 🔥 🌳 ⬜ 🌳 🌳 ⬜ ⬜ 🌳 🌳 
🌳 🌳 🌳 🌳 ⬜ 🌳 🌳 💧 🌳 🌳 
🌳 🌳 ⬜ 🌳 🌳 🌳 💧 💧 🌳 ⬜ 
🌳 🌳 ⬜ ⬜ 🌳 ⬜ 💧 🌳 🌳 🌳 
```
Na iteração 2, pode-se verificar o o fogo se espalhando nas direções ortognais e respeitando as regras de simualçao:
```
🌳 🌳 🌳 ⬜ 🌳 ⬜ 🌳 🌳 💧 🌳 
💧 🌳 🌳 🌳 🌳 🌳 ⬜ 🌳 💧 💧 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 ⬜ 🌳 🌳 
🌳 🌳 🌳 🌳 ⬜ 🌳 🌳 🐒 💧 🌳 
🌳 🌳 🌳 🌳 🌳 ⬜ 🌳 🌳 💧 🌳 
⬜ ⬜ 🌳 ⬜ 🌳 🌳 ⬜ 🌳 🌳 🌳 
🔥 🪵 🔥 ⬜ 🌳 🌳 ⬜ ⬜ 🌳 🌳 
🌳 🔥 🌳 🌳 ⬜ 🌳 🌳 💧 🌳 🌳 
🌳 🌳 ⬜ 🌳 🌳 🌳 💧 💧 🌳 ⬜ 
🌳 🌳 ⬜ ⬜ 🌳 ⬜ 💧 🌳 🌳 🌳 
```

No arquivo output.dat contém o mapeamento da propagação do fogo e do animal separadamente, afim de melhor compreender a dinâmica da simulação. Verifica-se que após 20 iterações o fogo consome as regiões disponíveis e o animal sobrevive, indo para uma região que possui água. A restauração da área consumida pelo fogo (aplicação da umidade) é realizada com sucesso. O Caminho percorrido pelo animal: (3,7)(3,8)(4,8)(5,8)(6,8)(6,7)(7,7).

```
--- Iteracao 20 ---
 --- Posição Animal  ---
🪵 🪵 🪵 ⬜ 🪵 ⬜ 🌳 🌳 💧 🌳 
💧 🪵 🪵 🪵 🪵 🪵 ⬜ 🌳 💧 💧 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 ⬜ 🪵 🪵 
🪵 🪵 🪵 🪵 ⬜ 🪵 🪵 🐒 🐒 🪵 
🪵 🪵 🪵 🪵 🪵 ⬜ 🪵 🪵 🐒 🪵 
⬜ ⬜ 🪵 ⬜ 🪵 🪵 ⬜ 🪵 🐒 🪵 
🪵 🪵 🪵 ⬜ 🪵 🪵 ⬜ 🐒 🐒 🪵 
🪵 🪵 🪵 🪵 ⬜ 🪵 🌳 🐒 🌳 🪵 
🪵 🪵 ⬜ 🪵 🪵 🪵 💧 💧 🪵 ⬜ 
🪵 🪵 ⬜ ⬜ 🪵 ⬜ 💧 🪵 🪵 🪵 

 --- Posição Fogo  ---
🪵 🪵 🪵 ⬜ 🪵 ⬜ 🌳 🌳 💧 🌳 
💧 🪵 🪵 🪵 🪵 🪵 ⬜ 🌳 💧 💧 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 ⬜ 🪵 🪵 
🪵 🪵 🪵 🪵 ⬜ 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 ⬜ 🪵 🪵 ⬜ 🪵 
⬜ ⬜ 🪵 ⬜ 🪵 🪵 ⬜ 🪵 🪵 🪵 
🪵 🪵 🪵 ⬜ 🪵 🪵 ⬜ 🌳 🪵 🪵 
🪵 🪵 🪵 🪵 ⬜ 🪵 🌳 ⬜ 🌳 🪵 
🪵 🪵 ⬜ 🪵 🪵 🪵 💧 💧 🪵 ⬜ 
🪵 🪵 ⬜ ⬜ 🪵 ⬜ 💧 🪵 🪵 🪵 

```
