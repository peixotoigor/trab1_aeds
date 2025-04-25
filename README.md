# <!-- titulo-->
<h1 align="center"> FireScape </h1>

<!-- TAGS-->

<p align="center">
  <img loading="lazy" src="http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=GREEN&style=for-the-badge" />
  <img loading="lazy" src="http://img.shields.io/static/v1?label=Linguagem&message=C%2B%2B&color=GREEN&style=for-the-badge" />
</p>
<!-- Imagem -->

<div align="center">
  <img src="https://github.com/user-attachments/assets/3fc3f4ea-1df9-461b-9073-ebe80a3b204c" alt="Logo_projeto" width="300" />
</div>

## Tópicos 

:small_blue_diamond: [Introdução](#Introduçao)

:small_blue_diamond: [Descrição do projeto](#descrição-do-projeto)

:small_blue_diamond: [Ambiente de Criação](#Ambiente-de-criacao)

:small_blue_diamond: [Estutura Geral do Projeto](#Estrutura-Geral-do-Projeto)

:small_blue_diamond: [Casos de teste](#Casos-de-teste)

:small_blue_diamond: [Implementação](#Implementacao)

:small_blue_diamond: [Instalação e Configuração](#Instalação-e-Configuracao)

:small_blue_diamond: [Desenvolvedores do Projeto](#Desenvolvedores-do-Projeto)

:small_blue_diamond: [Ambiente de teste](#Ambiente-de-teste)

:small_blue_diamond: [Recursos Utilizados](#Recursos-Utilizados)

:small_blue_diamond: [Licença](#Licença)


## :page_with_curl: Introdução
<p align="justify">
Incêndios florestais e urbanos são fenômenos que trazem consigo graves consequências ambientais, sociais e econômicas. A medida de como um incêndio se espalha, conhecida como taxa de propagação, é fundamental para prever o comportamento do fogo e implementar as respostas adequadas. Essa taxa pode ser afetada por uma variedade de fatores, incluindo condições climáticas, tipo de vegetação, umidade do solo, e características do terreno.
  
Além da destruição imediata, as consequências de um incêndio vão além do impacto ambiental, afetando a saúde pública através da qualidade do ar, a fauna e a flora locais, e até mesmo as economias locais, que dependem desses ecossistemas. A modelagem da taxa de propagação é, portanto, uma ferramenta vital e deve ser integrada em planos de manejo e resposta a emergências. Essa abordagem permite a identificação de áreas vulneráveis e a aplicação de medidas proativas para mitigação da propagação do fogo.
</p>
 
## :bookmark_tabs: Descrição do projeto

Este projeto busca o desenvolvimento de prótotipo de um simulador computacional destinado à modelagem da propagação de incêndios em uma floresta. A representação da área florestal é feita através de uma matriz bidimensional.  Esta estrutura de dados permite discretizar o espaço e modelar as relações de vizinhança entre diferentes porções da floresta.  Cada célula da matriz representa um quadrante da área florestal e é caracterizada por um estado, que evolui dinamicamente ao longo da simulação em função das regras de propagação do incêndio e da interação com outros elementos do modelo.
<p>
<p align="justify">
Além da simulação da propagação do incêndio, o projeto incorpora a modelagem do comportamento de um agente (animal) inserido neste ambiente.  O animal é capaz de se movimentar pela área florestal, buscando rotas de fuga seguras em relação ao fogo. 
<p>
<p align="justify">
Este trabalho foi proposto pelo professor Michel Pires Silva, instrutor da disciplina Algoritmos e Estrutura de Dados I, do Centro Federal de Educação Tecnológica de Minas Gerais (CEFET - MG), Campus V - Divinópolis.
<p>

### :pushpin: 1. Representação da Área Florestal
<p align="justify">
  A área da floresta será representada computacionalmente por meio de uma matriz bidimensional de dimensões NxM. Cada elemento (ou célula) desta matriz corresponderá a um quadrante específico da área florestal em simulação. A cada quadrante será atribuído um valor inteiro, representando o estado do elemento simulado naquele quadrante. Os estados possíveis são:  
</p>

- 0: Área vazia (não suscetível à combustão).  
- 1: Árvore saudável.  
- 2: Árvore em chamas.  
- 3: Árvore queimada (não propaga mais o fogo).  
- 4: Presença de água.  

### :pushpin: 2. Simulação da Propagação do Incêndio

<p align="justify">
  A propagação do incêndio será simulada de acordo com um conjunto de regras predefinidas. Estas regras ditam a transição dos estados das células da matriz ao longo do tempo, em iterações discretas da simulação.
</p>

#### 2.1 Regras de Propagação:
<p align="justify">
  Uma célula contendo uma árvore saudável (valor 1) evolui para o estado de árvore em chamas (valor 2) se ao menos uma de suas células vizinhas contiver uma árvore em chamas (valor 2). A propagação do fogo ocorre exclusivamente nas direções ortogonais (esquerda, direita, acima e abaixo).  
  Uma célula representando uma árvore em chamas (valor 2) transiciona para o estado de árvore queimada (valor 3) após um ciclo de simulação. Células neste estado não propagam mais o incêndio.  
</p>

#### 2.2 Variações na Propagação:
<p align="justify">
  A simulação deverá contemplar diferentes modelos de propagação do fogo:  
  
  * **Propagação sem influência do vento**: o fogo se propaga de forma linear nas quatro direções ortogonais.  
  * **Propagação com influência do vento**: o fogo se propaga em direções ortogonais específicas, configuradas em um arquivo de cabeçalho. O vento pode direcionar o fogo para uma ou mais direções (esquerda, direita, acima ou abaixo).  
</p>

#### 2.3 Condições de Término:
<p align="justify">
  A simulação da propagação do incêndio prossegue iterativamente até que não existam mais células representando árvores em chamas (valor 2) ou até que um número máximo de iterações (K) seja atingido.  
</p>

### :pushpin: 3. Simulação da Movimentação do Animal

<p align="justify">
  O modelo de simulação deverá incluir a movimentação de um animal dentro da área florestal. A movimentação do animal também será modelada em função da matriz representativa da floresta.  
</p>

#### 3.1 Regras de Movimentação:
<p align="justify">
  O animal, quando posicionado em uma célula segura (valor 0 ou 1), deve buscar uma nova posição segura nas direções ortogonais.  
  A prioridade na escolha da nova posição segue a seguinte ordem:  
</p>

* Posição com água (valor 4). 
* Posição vazia (valor 0) ou com árvore saudável (valor 1).  
*  Posição com árvore queimada (valor 3).  
* A posição do animal deve ser representada por uma variável externa à matriz.
* Se o animal estiver em uma posição segura (valor 0), poderá permanecer nela por até 3 iterações.
* Ao alcançar uma posição contendo água (valor 4), a célula é atualizada para o estado seguro (valor 0), e todas as células ortogonalmente adjacentes são convertidas para o valor 1.  
</p>

#### 3.2 Interação com o Incêndio:
<p align="justify">
  A movimentação do animal precede a propagação do incêndio em cada iteração.  
  Se a posição do animal for atingida pelo fogo, o animal tem uma nova oportunidade de se movimentar.  
  Esta oportunidade de fuga não é concedida se o animal estiver cercado por árvores recém-incendiadas (valor 2).  
</p>

#### 3.3 Registro de Movimentação:
<p align="justify">
  O deslocamento do animal deve ser monitorado, registrando-se o número total de passos, a quantidade de vezes em que encontrou água e a iteração em que ficou impossibilitado de prosseguir, se aplicável.  
</p>


## 🖥️ Ambiente de Criação

O código foi desenvolvido utilizando as seguintes ferramentas:

[![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)](https://learn.microsoft.com/cpp/)
[![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-blueviolet)](https://code.visualstudio.com/docs/?dv=linux64_deb)
[![Sistema Operacional](https://img.shields.io/badge/ISO-Ubuntu%20Linux%20WSL%2022.04-red)](https://ubuntu.com/wsl)


## :file_folder: Estrutura Geral do Projeto

A estrutura do projeto é disposto da seguinte maneira:

```markdown
trab1_aeds/
├── Makefile                # Script para compilar o projeto (build automático)
├── README.md               # Descrição geral do projeto e instruções de uso
├── build/                  # Diretório para arquivos binários/compilados
│   └── app                 # Executável principal gerado pela compilação
├── data/                   # Arquivos de dados de entrada e saída
│   ├── geradorMatriz.py    # Script Python para gerar matrizes de teste
│   ├── input.dat           # Arquivo de entrada padrão para a simulação
│   ├── matriz.dat          # Matriz gerada pelo script Python
│   ├── log.dat             # Log de execução da simulação
│   └── output.dat           # Saída final da simulação (resultados)
├── include/                # Arquivos de cabeçalho (headers) do projeto
│   ├── Simulador.hpp           # Declaração da classe/função principal da simulação
│   ├── config.hpp              # Configurações e constantes globais
│   ├── conferirFogo.hpp        # Funções para checar o fogo na matriz
│   ├── leitorMatriz.hpp        # Leitura de arquivos de matriz
│   ├── melhorMovimento.hpp     # Lógica de movimentação do animal
│   ├── numAleatorio.hpp        # Funções para geração de números aleatórios
│   ├── propagacaoFogo.hpp      # Lógica de propagação do fogo
│   ├── relatorio.hpp           # Funções para geração de relatórios
│   └── umidade.hpp             # Funções relacionadas à umidade/água
├── src/                    # Código-fonte principal do projeto
│   ├── Simulador.cpp           # Implementação da simulação principal
│   ├── conferirFogo.cpp        # Implementação das funções de fogo
│   ├── leitorMatriz.cpp        # Implementação da leitura de matriz
│   ├── main.cpp                # Função principal (main)
│   ├── melhorMovimento.cpp     # Implementação do movimento do animal
│   ├── numAleatorio.cpp        # Implementação dos números aleatórios
│   ├── propagacaoFogo.cpp      # Implementação da propagação do fogo
│   ├── relatorio.cpp           # Implementação dos relatórios
│   ├── umidade.cpp             # Implementação da lógica de umidade
└── .vscode/                # Configurações do Visual Studio Code
    └── settings.json           # Configurações específicas do projeto
```

## :man_technologist: Implementação

Antes de iniciar a simulação, é necessário configurar os parâmetros globais disponíveis no arquivo [config.hpp](https://github.com/peixotoigor/trab1_aeds/blob/main/include/config.hpp). Este arquivo centraliza constantes e estruturas que controlam limites operacionais e fatores ambientais, como o vento, permitindo ajustes rápidos e organizados sem alterar o código-fonte principal.

#### Limites Operacionais:
  * MAX_ITERACOES: Define o número máximo de iterações permitidas (100 por padrão), evitando execuções infinitas e controlando o tempo de simulação.
  * MAX_PERMANENCIA: Especifica quantas iterações o animal pode permanecer em uma célula segura ('0') antes de ser obrigado a se mover (3 por padrão), equilibrando estratégia de sobrevivência e dinâmica do ambiente.

#### Mapeamento de Direções:
DIRECOES_VENTO: Associa cada elemento do enum DIRECOES a um deslocamento concreto na matriz (variação de linhas e colunas):
```cpp
{-1, 0}, // Cima (linha -1)
{1, 0},  // Baixo (linha +1)
{0, -1}, // Esquerda (coluna -1)
{0, 1}   // Direita (coluna +1)
```

#### Controle do Vento:
  * VENTO_ATIVO: Booleano que ativa (true) ou desativa (false) a influência do vento na propagação do fogo.
  * DIRECOES (Enumeração): Lista direções possíveis para o vento:

```cpp
// Variável para definir as direções do vento (pode conter várias direções)
const std::vector<DIRECOES> VENTO_DIRECOES = VENTO_ATIVO 
    ? std::vector<DIRECOES>{ABAIXO, DIREITA} // Direções configuradas quando o vento está ativo
    : std::vector<DIRECOES>{ESQUERDA, DIREITA, ACIMA, ABAIXO}; // Todas as direções quando SEM_VENTO
```
Assim como é possível modificar os parâmetros da simulação, é possível gerar matrizes diferentes com o utilizando o script em Python [geradorMatriz.py](data/geradorMatriz.py) Nele é possível alterar o tamanho da malha, a distribuição da quantidade de espaços vazios, quantidade de árvores saudáveis, espaços vazios e presença de água. Para modificar, basta alterar os valores multiplicadores das funções associadas.

Código: Dimensão da matriz e cálculo de distribuição
```python
# Dimensão da matriz
rows, cols = 10, 10

# Cálculo do total de células e distribuição
total_cells = rows * cols  
num_ones = int(total_cells * 0.8)  # arvores saudaveis
num_zeros = int(total_cells * 0.1) # espaços vazios
num_fours = total_cells - num_ones - num_zeros  # agua
```
Para maior clareza da descrição a seguir, é interessante acompanhar o [diagrama](diagrama.md) do funcionamento completo do código.

A simulação inicia sua execução com o módulo [leitorMatriz.cpp](https://github.com/peixotoigor/trab1_aeds/blob/main/src/leitorMatriz.cpp), responsável por carregar e validar o arquivo input.dat, que contém a configuração inicial do ambiente. Esse arquivo inclui dados (número de linhas, colunas, coordenadas iniciais do fogo) e uma matriz de caracteres representando os estados das células: '0' (seguro), '1' (árvore saudável), '2' (fogo ativo), '3' (queimado) e '4' (água). É valido ressaltar que o arquivo input.dat pode ser gerado utilizando um script em Python disponível em [geradorMatriz.py](https://github.com/peixotoigor/trab1_aeds/blob/main/data/geradorMatriz.py) 

A validação garante que todas as células contenham valores válidos, abortando a simulação em caso de erro e registrando detalhes em log.dat. Após a leitura, a matriz é armazenada em um 'vector<vector<char>>', estrutura escolhida por sua flexibilidade para redimensionamento dinâmico e acesso rápido via índices. Além disso, é armazenada a posição inicial do fogo na matriz. Para melhorar a dinâmica de execução, foi definida uma função chamada [numAleatorio](src/numAleatorio.cpp)] que gera um número dentro dos limites da matriz. Essa função é utilizada para mapear posições da linha e coluna para o agente (animal) na simulação. Uma estratégia utilizada para garantir que a posição do fogo e do animal não coincidam foi retirar uma unidade da posição do animal. 
```cpp
    int posAnimalX = numeroAleatorio(0, linhas)-1;
    int posAnimalY = numeroAleatorio(0, colunas)-1;
```

Em seguida, o Simulador.cpp assume o controle, inicializando a propagação do fogo com uma fila FIFO (queue<pair<int, int>> filaFogo), que prioriza células em chamas na ordem de ignição. A posição inicial do fogo (fogoInicialX, fogoInicialY) é marcada como '2' e adicionada à fila. Paralelamente, o animal é posicionado aleatoriamente usando a função numeroAleatorio() (definida em numAleatorio.cpp), que gera coordenadas dentro dos limites da matriz, garantindo que a simulação comece com condições variáveis. O histórico de movimentos do animal é registrado em um vector<pair<int, int>> caminhoPercorrido, permitindo evitar loops ao priorizar células não visitadas.

O loop principal, limitado por MAX_ITERACOES, executa as seguintes etapas iterativamente:

Registro do Estado: relatorio.cpp salva a matriz em output.dat, substituindo células do caminho do animal por * para visualização clara.

Verificação de Água: Se o animal está em '4', umidade.cpp é acionado, convertendo a célula de água em '0' (segura) e regenerando células adjacentes: fogo ('2') vira '1' (extinção local), e outras (exceto '4') são marcadas como saudáveis.

Movimentação do Animal: melhorMovimento.cpp avalia as 4 direções ortogonais (DIRECOES_ORTOGONAIS), atribuindo prioridades: '4' (prioridade 1) > '0' (2) > '1' (3) > '3' (4). Células em fogo ('2') são ignoradas, e células não visitadas são priorizadas. Se todas as opções forem visitadas, o algoritmo permite revisitar células com menor prioridade. A nova posição é adicionada ao caminhoPercorrido, e o contador de passos é incrementado.

Propagação do Fogo: propagacaoFogo.cpp processa a fila de fogo, convertendo cada '2' em '3' (queimado) e propagando chamas para células '1' adjacentes, seguindo as direções do vento (VENTO_DIRECOES). Novos focos ('2') são enfileirados para processamento na próxima iteração.

Verificação de Sobrevivência: conferirFogo.cpp checa se o animal está em '2'. Em caso positivo, tenta movê-lo para células seguras ('0', '1', '4'). Se falhar, define animalVivo = false, encerrando o loop.

As condições de parada são verificadas a cada ciclo:

Fogo Extinto: A função areaConsumidaPeloFogo() (em Simulador.cpp) varre a matriz em busca de '2'. Se ausentes, a simulação termina.

Morte do Animal: Caso cercado por fogo sem rotas de fuga.

Limite de Iterações: MAX_ITERACOES é atingido.

Ao final, relatorio.cpp gera um relatório em log.dat com o caminho completo, número de passos, status de sobrevivência e matriz final. Já output.dat armazena snapshots iterativos, permitindo análise pós-simulação. A escolha de estruturas como queue para o fogo (FIFO) e vector para o caminho equilibra eficiência e simplicidade, enquanto a modularidade do código facilita a extensão


##  :test_tube:  Casos de teste 
Para verificar o comportamento da simulação foram testados os seguintes casos
  * [Propagação sem a influência do vento]()
  * [Propagação com a influência do vento]()
  * [Segunda chance]()

#### 1. Início e Leitura de Dados

O programa inicia lendo a matriz de entrada, que representa a floresta, a posição inicial do fogo e demais parâmetros necessários para a simulação.  
Essa matriz pode ser gerada manualmente ou por meio de um script Python fornecido no projeto.

---
</p>
#### 2. Inicialização

Variáveis de controle são inicializadas, incluindo:  
- A posição do animal.  
- A fila de propagação do fogo.  
- Contadores de iteração.  
- Flags de status (animal vivo, chegou à água, etc.).  
- Estruturas para registrar o caminho percorrido pelo animal.

---

#### 3. Loop Principal da Simulação

O programa entra em um laço principal que representa o avanço do tempo na simulação. Este laço continua até que uma **condição de parada** seja atingida:  
- Animal morto.  
- Toda a área consumida pelo fogo.  
- Número máximo de iterações.

#### **Dentro de cada iteração do loop**:

##### 3.1 Movimentação do Animal:  
- O animal avalia as células vizinhas e decide seu próximo movimento com base em prioridades: água, área segura, árvore saudável, etc.  
- Evita retornar para posições já visitadas, exceto em situações de borda.

##### 3.2 Propagação do Fogo:  
- O fogo se propaga para células vizinhas de acordo com as regras do simulador, utilizando uma fila para processar apenas as células em chamas.

##### 3.3 Verificação de Estado do Animal:  
- O programa verifica se o animal foi atingido pelo fogo.  
- Se possível, tenta movê-lo para uma célula segura.  
- Caso contrário, o animal é considerado morto.

##### 3.4 Verificação de Condições de Parada:  
- O simulador checa se o animal morreu.  
- Se toda a área foi consumida pelo fogo.  
- Se o número máximo de iterações foi atingido.  
- Caso qualquer uma dessas condições seja satisfeita, o loop é encerrado.

##### 3.5 Salvamento do Estado Atual:  
- O estado da matriz e o caminho percorrido pelo animal são registrados para análise posterior.

---

#### 4. Geração do Relatório Final

Após o término do loop principal, o programa gera um relatório final contendo:  
- O estado final da matriz.  
- O caminho percorrido pelo animal.  
- O número de passos.  
- O status final do animal (sobreviveu, morreu, chegou à água, etc.).

---

####  5. Término

O programa encerra sua execução, deixando os resultados disponíveis nos arquivos de saída para análise.

## :keyboard: Instalação e Configuração 

Para a execução correta do software é interessante  os seguintes requisitos e dependências:
  * C++17 ou superior (compilador: g++ recomendado)
  * Python 3.12.3 ou superior (para geração de matrizes de teste)
  * Make (para build automatizado)
  * Linux  (desenvolvido/testado em Ubuntu, mas portável)

### **Passos e Comandos**

#### **1. Verificar e Instalar o Compilador C++ (`g++`)**
Verifique a versão instalada:
```bash
g++ --version
```
Se a versão for inferior a C++17, instale:
```bash
sudo apt update
sudo apt install g++ -y
```
#### **2. Verificar e Instalar Python 3.12.3 ou Superior**
Verifique a versão instalada:
```bash
python3 --version
```
Se a versão não for a desejada, atualize ou instale::
```bash
sudo apt update
sudo apt install python3 -y
```
#### **3. Verificar e Instalar Make**
Verifique a versão instalada:
```bash
make --version
```
Se a versão não for a desejada, atualize ou instale::
```bash
sudo apt update
sudo apt install make -y
```

#### **4. Clone o repositório**
No termimal digite o seguinte comando para clonar o repositório e posteriomente acessar o projeto:
```bash
git clone https://github.com/peixotoigor/trab1_aeds.git
cd trab1_aeds
```
#### **5.Gere uma matriz de entrada (opcional):**
Para gerar uma matriz com tamanho e configurações da malha diferentes acesse o arquivo que esta na pasta data/:
```bash
cd data
```
O arquivo geradorMatriz.py é capaz de gerar matrizes diferentes sendo possível alterar o tamanho da malha, a distribuição da quantidade de espaços vazios, quantidade de árvores saudáveis, espaços vazios e presença de água. Para modificar, basta alterar os valores multiplicadores das funções associadas.

Código: Dimensão da matriz e cálculo de distribuição
```python
# Dimensão da matriz
rows, cols = 10, 10

# Cálculo do total de células e distribuição
total_cells = rows * cols  
num_ones = int(total_cells * 0.8)  # arvores saudaveis
num_zeros = int(total_cells * 0.1) # espaços vazios
num_fours = total_cells - num_ones - num_zeros  # agua
```
Retorne para a raiz do diretório:
```bash
cd ..
```

#### **6. Compile o projeto:**
Para compilar o projeto:
```bash
make
```
Observações: para cada alteração das matrizes é necessário, compilar o projeto. Assim, execute:
```bash
make clean
make
```
#### **7. Execute o projeto:**
```bash
./build/app
```
####  8. Guia de Uso

##### Execução do Programa
O programa irá:
- Ler o arquivo de entrada.
- Executar a simulação.
- Salvar os resultados em **saida.dat** e **log.dat**.

##### Parâmetros Configuráveis

Ajuste os parâmetros globais no arquivo `config.hpp`, como:
- Número máximo de iterações.
- Permanência máxima.
- Configurações de vento.

##### Saídas

- **output.dat**: Registro de cada iteração e o estado final da matriz.  
- **log.dat**: Logs de execução e possíveis erros.


## :busts_in_silhouette: Desenvolvedores do Projeto
[<img loading="lazy" src="https://avatars.githubusercontent.com/u/106671313" width=115><br><sub>Igor Peixoto</sub>](https://github.com/peixotoigor)

## :computer: Ambiente de teste
Este projeto foi executado utilizando:
  * **Sistema Operacional**: Linux Ubuntu WSL @ Windows 11 (Windows Subsystem for Linux).
  * **Compilador**: GCC 13.3.0
  * **Hardware**: 13th Gen Intel(R) Core(TM) i7-13620H @ 2.40GHz, 24GB RAM, 512GB SSD, NVIDIA GeForce RTX 4050.
    

## :gear: Recursos Utilizados
<p align="left">
  <img alt="Visual Studio Code" height="60" width="60" src="https://github.com/gui-bus/TechIcons/blob/main/Dark/VSCode.svg">
  <img alt="C++" height="60" width="60" src="https://github.com/gui-bus/TechIcons/blob/main/Dark/C++.svg">
</p>


## :scroll: Licença 
Copyright :copyright: 2025 - FireScape
