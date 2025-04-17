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

:small_blue_diamond: [ Estutura Geral do Projeto](#Estrutura-Geral-do-Projeto)

:small_blue_diamond: [Como rodar a aplicação](#como-rodar-a-aplicação-arrow_forward)

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

## Estutura Geral do Projeto
```markdown
/SimuladorFloresta
│
├── main.cpp                  // Apenas chama a função executarSimulacao()
├── config.hpp                // Constantes globais e configurações da simulação
│
├── Simulador.hpp             // Declara a função que gerencia a simulação completa
├── Simulador.cpp             // Implementa a função executarSimulacao()
│
├── leitorMatriz.hpp          // Declara a classe para leitura do arquivo
├── leitorMatriz.cpp          // Implementa a leitura e armazenamento dos dados
│
├── Fogo.hpp                  // Declara a classe Fogo (propagação do incêndio)
├── Fogo.cpp                  // Implementa a propagação do fogo usando diretamente a matriz
│
├── Animal.hpp                // Declara a classe Animal (movimentação do animal)
├── Animal.cpp                // Implementa a movimentação e as regras do animal
│
├── Relatorio.hpp             // Declara a classe para gerar relatório da simulação
├── Relatorio.cpp             // Implementa a geração do relatório
│
└── entrada.txt               // Arquivo de entrada contendo a matriz e dados iniciais
 ```

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
