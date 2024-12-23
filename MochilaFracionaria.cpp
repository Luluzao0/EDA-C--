#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Define a estrutura para armazenar itens com peso e valor.
struct Item
{
    int peso;
    // Função para ordenar itens pelo valor por unidade de peso.
    int valor;
    double valorPorPeso;
};
// Função para resolver o problema da mochila fracionária usando o método guloso.

bool compararItens(const Item &a, const Item &b)
{
    // Ordena os itens pelo valor por unidade de peso.
    return a.valorPorPeso > b.valorPorPeso;
}

double mochilaFracionaria(int capacidade, vector<Item> &itens)
{
    sort(itens.begin(), itens.end(), compararItens);
    // Adiciona o item completo ou uma fração dele à mochila.

    double valorTotal = 0;
    int pesoAtual = 0;

    for (const auto &item : itens)
    {
        if (pesoAtual + item.peso <= capacidade)
        {
            valorTotal += item.valor;
            pesoAtual += item.peso;
        }
        else
        {
            // Função principal para testar a solução da mochila fracionária.
            int pesoRestante = capacidade - pesoAtual;
            valorTotal += item.valorPorPeso * pesoRestante;
            break;
        }
    }

    return valorTotal;
}

int main()
{
    int capacidade = 50;
    vector<Item> itens = {
        {10, 60, 6.0},
        {20, 100, 5.0},
        {30, 120, 4.0}};

    cout << fixed << setprecision(2);
    cout << "Valor total na mochila: " << mochilaFracionaria(capacidade, itens) << endl;

    return 0;
}