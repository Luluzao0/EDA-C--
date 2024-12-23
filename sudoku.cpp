#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para verificar se uma grade de Sudoku é válida.
bool ehValido(const vector<vector<int>> &grade)
{
    // Verifica linhas
    // Verifica se as linhas contêm valores válidos.
    for (int i = 0; i < 9; ++i)
    {
        vector<int> linha = grade[i];
        sort(linha.begin(), linha.end());
        for (int j = 0; j < 8; ++j)
        {
            if (linha[j] != 0 && linha[j] == linha[j + 1])
            {
                return false;
            }
        }
    }

    // Verifica se as colunas contêm valores válidos.
    // Verifica colunas
    for (int j = 0; j < 9; ++j)
    {
        vector<int> coluna;
        for (int i = 0; i < 9; ++i)
        {
            coluna.push_back(grade[i][j]);
        }
        sort(coluna.begin(), coluna.end());
        for (int i = 0; i < 8; ++i)
        {
            if (coluna[i] != 0 && coluna[i] == coluna[i + 1])
            {
                return false;
                // Verifica se as subgrades 3x3 contêm valores válidos.
            }
        }
    }

    // Verifica subgrades 3x3
    for (int blocoLinha = 0; blocoLinha < 3; ++blocoLinha)
    {
        for (int blocoColuna = 0; blocoColuna < 3; ++blocoColuna)
        {
            vector<int> bloco;
            for (int i = blocoLinha * 3; i < (blocoLinha + 1) * 3; ++i)
            {
                for (int j = blocoColuna * 3; j < (blocoColuna + 1) * 3; ++j)
                {
                    bloco.push_back(grade[i][j]);
                }
            }
            sort(bloco.begin(), bloco.end());
            // Função principal para testar a solução do Sudoku.
            for (int i = 0; i < 8; ++i)
            {
                if (bloco[i] != 0 && bloco[i] == bloco[i + 1])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> grade(9, vector<int>(9));

    // Exemplo de grade (preencha com os valores desejados)
    // ...

    if (ehValido(grade))
    {
        cout << "A grade eh valida." << endl;
    }
    else
    {
        cout << "A grade nao eh valida." << endl;
    }

    return 0;
}