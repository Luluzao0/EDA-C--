#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Atividade
{
    // Define a estrutura para armazenar as atividades com horários de início e término.
    int inicio;
    int termino;
    // Função para comparar atividades pelo horário de término.
};

bool comparaAtividades(const Atividade &a, const Atividade &b)
{
    return a.termino < b.termino;
    // Função que seleciona o maior número de atividades possíveis sem conflitos.
}
// Ordena as atividades pelo horário de término.

vector<Atividade> selecionaAtividades(vector<Atividade> &atividades)
{
    // Cria um vetor para armazenar as atividades selecionadas.
    sort(atividades.begin(), atividades.end(), comparaAtividades);
    // Se houver atividades, inicia selecionando a primeira.

    vector<Atividade> atividadesSelecionadas;
    if (!atividades.empty())
    {
        // Verifica atividades restantes e adiciona as que não conflitam.
        atividadesSelecionadas.push_back(atividades[0]);
        int ultimoTermino = atividades[0].termino;

        for (int i = 1; i < atividades.size(); ++i)
        {
            if (atividades[i].inicio >= ultimoTermino)
            {
                atividadesSelecionadas.push_back(atividades[i]);
                ultimoTermino = atividades[i].termino;
            }
        }
    }
    return atividadesSelecionadas;
}
// Função principal para testar a seleção de atividades.

int main()
{
    vector<Atividade> atividades = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};

    vector<Atividade> selecionadas = selecionaAtividades(atividades);

    cout << "Atividades selecionadas:\n";
    for (const auto &atividade : selecionadas)
    {
        cout << "Inicio: " << atividade.inicio << ", Termino: " << atividade.termino << endl;
    }

    return 0;
}