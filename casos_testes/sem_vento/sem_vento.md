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

Para facilitar a visualização, definiu-se as seguintes figuras para representar cada estado:
    
    * Espaço vazio (0): ⬜
    * Árvore saúdavel (1): 🌳 
    * Incêndio (2): 🔥
    * Árvore saúdavel (3): 🪵
    * Água (4): 💧

A condição inicial 
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