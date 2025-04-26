## Caso 3: Segunda vida

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
A matriz utilizada, no tamanho 10x10, gerada através do script [geradorMatriz.pu](data/geradorMatriz.py) foi configurada para que 99% da aréa fosse composta por árvores saudáveis, 0% por espaços vazios e 1% contendo água:
```pyhton
num_ones = int(total_cells * 0.99)  # arvores saudaveis
num_zeros = int(total_cells * 0.) # espaços vazios
num_fours = total_cells - num_ones - num_zeros  # agua
```
No qual resultou na matriz:
```
10 10 6 3
1 1 1 1 1 1 1 1 1 1
1 1 1 4 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 2 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
```
Assim , posição inicial para o fogo foi linha 6 e coluna 3 (lembrando que o índice começa em 0).
Para facilitar a visualização, definiu-se as seguintes figuras para representar cada estado:

    * Espaço vazio (0): ⬜
    * Árvore saúdavel (1): 🌳 
    * Incêndio (2): 🔥
    * Árvore saúdavel (3): 🪵
    * Água (4): 💧

A cposição inicial do agente, representado por 🐒, foi estabelecida aleatoriamente, e encontrou-se na linha 3 e coluna 7. O ambiente de simulação inical (iteração 1) pode ser visualizado abaixo:
```
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 💧 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🐒 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🔥 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
```
Na iteração 2, pode-se verificar o o fogo se espalhando nas direções ortognais e respeitando as regras de simualçao:
```
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 💧 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🐒 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🐒 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🔥 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🔥 🪵 🔥 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🔥 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
```

No arquivo output.dat contém o mapeamento da propagação do fogo e do animal separadamente, afim de melhor compreender a dinâmica da simulação. Verifica-se que após 8 iterações o animal se depara com o fogo na posição (2,6) e o mecanismo de segunda vida é ativado:

```
--- Iteracao 8 ---
 --- Posição Animal  ---
🌳 🌳 🔥 🌳 🔥 🌳 🐒 🐒 🌳 🌳 
🌳 🔥 🪵 💧 🪵 🔥 🐒 🐒 🌳 🌳 
🔥 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🌳 🌳 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🐒 🌳 🌳 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 🌳 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 🌳 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 🌳 🌳 

 --- Posição Fogo  ---
🌳 🌳 🔥 🌳 🔥 🌳 🌳 🌳 🌳 🌳 
🌳 🔥 🪵 💧 🪵 🔥 🌳 🌳 🌳 🌳 
🔥 🪵 🪵 🪵 🪵 🪵 🔥 🌳 🌳 🌳 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 🌳 🌳 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 🌳 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 🌳 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 🌳 🌳
```

O agente entao inicia a procura de uma rota de fuga para escapar do incêncio. Como o animal se vê encurralado pelo fogo, e acaba não sobrevivendo na iteração 12. O Caminho percorrido pelo animal:(3,7)(2,7)(1,7)(0,7)(0,6)(1,6)(2,6)(1,6)(0,6)(0,7)(0,8)(0,9)

```
--- Iteracao 12 ---
 --- Posição Animal  ---
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🐒 🐒 
🪵 🪵 🪵 💧 🪵 🪵 🐒 🐒 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🐒 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 

 --- Posição Fogo  ---
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 
🪵 🪵 🪵 💧 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 

```

Em análise verifica-se que as regras de propagação estão sendo realizadas de forma esperada, assim como do agente. Uma suposição que surge partindo da análise do caminho agente está no fato de a prioridade por busca de ambientes que possuam água está sendo estabelicida. Para tal, partindo do ambiente já gerado, com uma modificação manual no ambiente de simulação ([input2.dat](casos_teste/sem_vida/input2.dat)), colocando a propagação mais afastada do agente (9,0), executou-se a simulação. 

```
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 💧 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🐒 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🔥 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
```

Após 18 iterações, o animal não sobrevive pois atualmente o coódigo não define uma mecanismo adequado para realizar tal busca. 

```
--- Iteracao 18 ---
 --- Posição Animal  ---
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🐒 🐒 
🪵 🪵 🪵 💧 🪵 🪵 🐒 🐒 🐒 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🐒 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🐒 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🐒 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 

 --- Posição Fogo  ---
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 
🪵 🪵 🪵 💧 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵
```

Forçando a posição do fogo e do agente - a modificação do agente foi realizada no arquivo [Simulador.cpp](scr/Simulador.cpp):
```cpp
// Posição aleatória do animal
    int posAnimalX = 7;
    int posAnimalY = 2;
    //int posAnimalX = numeroAleatorio(0, linhas)-1;
    //int posAnimalY = numeroAleatorio(0, colunas)-1;
    std::vector<std::pair<int, int>> caminhoPercorrido;
    caminhoPercorrido.push_back({posAnimalX, posAnimalY});
```
 e a modiciação da posição incial do incêncido foi feita diretamente no arquivo de entrada ([input3.dat](casos_teste/sem_vida/input3.dat)). Assim a o foco inicial (9,0) e agente (7,2). Por fim, executou a simulação.
```
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 💧 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🐒 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
🔥 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 🌳 
```

Após 18 iterações o animal sobrevive, pois encontra uma posição que possui água. 
```
--- Iteracao 18 ---
 --- Posição Animal  ---
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🐒 🐒 
🪵 🪵 🪵 💧 🪵 🪵 🐒 🐒 🐒 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🐒 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🐒 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🐒 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🐒 🐒 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 

 --- Posição Fogo  ---
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🔥 
🪵 🪵 🪵 💧 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 
🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 🪵 

```
Analisando o caminho do agente: (3,7)(2,7)(1,7)(0,7)(0,6)(1,6)(2,6)(3,6)(4,6)(5,6)(5,7)(4,7)(4,8)(3,8)(2,8)(1,8)(0,8)(0,9). Observa-se que a sobrevivencia do agente está relacionada com a forma com que a configuração de movimento foi estabelicida na função [buscarMelhorMovimento()](src/melhorMovimento.cpp). A função utiliza a primeira posição de movimento que é (-1,0), associada a um movimento para cima e não a posição que minimiza a distância entre o agente e a localização da água. Logo, analisando a posição incial do agente que está abaixo do local com água, fica evidente que este encontrará a posição com água e devido as regras de permanência e o tamanho da matriz, acabará sobrevivendo.

Uma forma de contornar esse desafio, é a inclusão de um mecanismo de verificação de distaância (algortimo Manhattan, por exemplo) entre o agente e áreas contendo água para determinar o melhor movimento. Assim, o agente se tornará mais "inteligente", aumentando sua taxa de sobrevivência.
