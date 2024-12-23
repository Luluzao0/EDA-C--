#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Função para verificar se uma posição é segura para a rainha.
bool isSafe(vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
        {
            return false;
        }
        // Função recursiva para resolver o problema das N rainhas.
    }
    return true;
    // Se todas as rainhas forem posicionadas, retorna verdadeiro.
}

bool solveNQueensUtil(vector<int> &board, int row, int n)
{
    if (row == n)
    {
        return true; // Todas as rainhas foram posicionadas
    }

    // Retrocede se não houver posição válida na linha atual.
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            if (solveNQueensUtil(board, row + 1, n))
            {
                return true;
            }
            // Função principal para configurar e resolver o problema.
            board[row] = -1; // Backtrack: desfaz a escolha
        }
    }
    return false; // Não encontrou solução para esta linha
}

void solveNQueens(int n)
{
    vector<int> board(n, -1); // Inicializa o tabuleiro com -1 (sem rainha)

    if (solveNQueensUtil(board, 0, n))
    {
        cout << "Solução encontrada:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i] == j)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Não há solução para N = " << n << endl;
    }
}

int main()
{
    int n;
    cout << "Digite o valor de N: ";
    cin >> n;
    solveNQueens(n);
    return 0;
}