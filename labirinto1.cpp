#include <iostream>
#include <vector>

using namespace std;

// Função que resolve o labirinto usando backtracking.
bool resolverLabirinto(vector<vector<int>>& labirinto, int linha, int coluna, int linhas, int colunas) {
// Verifica se a posição é válida para movimento.
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas || labirinto[linha][coluna] != 0) {
        return false;
    }
// Retorna verdadeiro se atingir o destino.

    if (labirinto[linha][coluna] == 3) { // Chegou ao fim
// Marca a posição atual como visitada.
        return true;
    }
// Tenta mover em todas as direções (Norte, Sul, Oeste, Leste).

    labirinto[linha][coluna] = 2; // Marca como visitado

    if (resolverLabirinto(labirinto, linha - 1, coluna, linhas, colunas) || // Norte
        resolverLabirinto(labirinto, linha + 1, coluna, linhas, colunas) || // Sul
        resolverLabirinto(labirinto, linha, coluna - 1, linhas, colunas) || // Oeste
// Desfaz a marcação caso não haja caminho.
        resolverLabirinto(labirinto, linha, coluna + 1, linhas, colunas)) { // Leste
        return true;
    }

// Função principal para testar a solução do labirinto.
    labirinto[linha][coluna] = 0; // Backtracking
    return false;
}

int main() {
    vector<vector<int>> labirinto = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 3} // Fim
    };

    int linhas = labirinto.size();
    int colunas = labirinto[0].size();

    if (resolverLabirinto(labirinto, 0, 0, linhas, colunas)) {
        cout << "Labirinto resolvido:" << endl;
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cout << labirinto[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Nao ha solucao." << endl;
    }

    return 0;
}