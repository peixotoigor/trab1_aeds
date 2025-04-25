#include "areaConsumida.hpp"

// Verifica se toda a área foi consumida pelo fogo (não há mais '1' ou '2')
bool areaConsumidaPeloFogo(const std::vector<std::vector<char>>& matriz) {
    for (const auto& linha : matriz) {
        for (char celula : linha) {
           //if (celula == '2'|| celula=='1') {
           if (celula == '2') {
                return false; // Ainda há fogo
            }
        }
    }
    return true; // Tudo foi queimado ou virou outro estado
}