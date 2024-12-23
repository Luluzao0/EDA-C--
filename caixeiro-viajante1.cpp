#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
// Função para calcular o custo mínimo do problema do caixeiro viajante.

int tsp(vector<vector<int>> &graph)
{
    // Preenche um vetor com os vértices das cidades.
    int n = graph.size();
    vector<int> vertices(n);
    for (int i = 0; i < n; ++i)
    {
        vertices[i] = i;
    }

    // Itera por todas as permutações possíveis das cidades.
    int min_path = numeric_limits<int>::max();
    do
    {
        int current_path = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            current_path += graph[vertices[i]][vertices[i + 1]];
        }
        current_path += graph[vertices[n - 1]][vertices[0]]; // Volta para o início
                                                             // Calcula o custo mínimo para todas as permutações.
        min_path = min(min_path, current_path);
    } while (next_permutation(vertices.begin() + 1, vertices.end())); // Permuta apenas os vértices intermediários

    return min_path;
}

// Função principal para definir o grafo e calcular o custo mínimo.
int main()
{
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0},
    };

    int min_cost = tsp(graph);
    cout << "Custo mínimo: " << min_cost << endl;

    return 0;
}