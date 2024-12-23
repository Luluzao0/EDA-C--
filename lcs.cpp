#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string lcs(string s1, string s2)
{
    int m = s1.length();
    // Função para calcular a subsequência comum mais longa entre duas strings.
    int n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // Inicializa a tabela de programação dinâmica.

    for (int i = 1; i <= m; i++)
    {
        // Constrói a tabela com base em caracteres iguais ou diferentes.
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // Reconstrói a LCS a partir da tabela.

    string lcs_str = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs_str = s1[i - 1] + lcs_str;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
            // Função principal para testar a LCS.
        }
        else
        {
            j--;
        }
    }
    return lcs_str;
}

int main()
{
    string s1 = "ABCBDAB";
    string s2 = "BDCABA";
    cout << "LCS: " << lcs(s1, s2) << endl; // Saída: BCBA
    return 0;
}