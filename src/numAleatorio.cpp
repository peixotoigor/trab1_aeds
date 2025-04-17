#include "numAleatorio.hpp"
#include <random>

int numeroAleatorio(int min, int max) {
    static std::mt19937 gen(42); // Inicializa o gerador com uma semente fixa (42)
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}
