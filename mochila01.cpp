#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mochila01(int W, vector<int> &peso, vector<int> &valor, int n)
{
    // Função para resolver o problema da mochila 0/1 com programação dinâmica.
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Inicializa a matriz de programação dinâmica.
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            // Preenche a matriz considerando inclusão ou exclusão do item.
            if (peso[i - 1] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(dp[i - 1][w], valor[i - 1] + dp[i - 1][w - peso[i - 1]]);
            }
        }
    }

    return dp[n][W];
}
// Função principal para testar a solução da mochila.

int main()
{
    int W = 50;
    vector<int> valor = {60, 100, 120};
    vector<int> peso = {10, 20, 30};
    int n = valor.size();

    cout << "Valor máximo na mochila: " << mochila01(W, peso, valor, n) << endl; // Output: 220

    return 0;
}