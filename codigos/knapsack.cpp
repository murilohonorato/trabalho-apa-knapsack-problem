#include <bits/stdc++.h>
#include "knapsack.hpp"
using namespace std;

bool Knapsack::compararRazao(Item a, Item b) { //compara para ordenar decrescente pela razão
    return a.razao > b.razao;
}

void Knapsack::printItens() {
    cout << "Itens disponíveis:\n";
    cout << "ID - Peso - Valor - Razão (V/P)\n";
    cout << fixed << setprecision(2);
    for (auto item : itens) {
        cout << item.id << " - " << item.peso << " - " << item.valor << " - " << item.razao << "\n";
    }
    cout << "-----------------------------\n";
}

void Knapsack::imprimirPasso(Item item, double peso_usado, double valor_pego, double restante, int tipo) {
    if (tipo == 0) { //Pega tudo
        cout << "Pegou 100% do item " << item.id 
             << " (Peso: " << peso_usado << ", Valor: " << valor_pego 
             << "). Capacidade restante: " << restante << "\n";

    } else { //Pega fração
        double fracao = peso_usado / (1.0*item.peso);
        cout << "Pegou " << (fracao * 100) << "% do item " << item.id 
             << " (Peso: " << peso_usado << "/" << item.peso 
             << ", Valor: " << valor_pego 
             << "). Capacidade restante: 0.00\n";
    }
}

double Knapsack::fracionaria() {
    sort(itens.begin(), itens.end(), compararRazao); //ordena os itens pela razão decrescente

    double valor_total = 0.0;
    int capacidade_atual = capacidade;

    for (auto item : itens) {
        if (capacidade_atual <= 0) break;

        if (item.peso <= capacidade_atual) { //pega tudo
            capacidade_atual -= item.peso;
            valor_total += item.valor;
        } else { //pega fração
            double fracao = capacidade_atual/(1.0*item.peso);
            double valor_fracao = item.valor*fracao;
            valor_total += valor_fracao;
            capacidade_atual = 0;
        }
    }
    return valor_total;
}

double Knapsack::binariaRecursiva(int capacidade, int index) {
    if (index == (int)itens.size() || capacidade == 0) return 0;

    if (itens[index].peso > capacidade) return binariaRecursiva(capacidade, index+1); //ignora o item atual

    double incluir = itens[index].valor + binariaRecursiva(capacidade - itens[index].peso, index+1); //inclui o item 
    double nao_incluir = binariaRecursiva(capacidade, index+1); //n inclui o item

    return max(incluir, nao_incluir);
}

double Knapsack::binaria() {
    return binariaRecursiva(capacidade, 0);
}

double Knapsack::binariaDP() {
    //Otimização de espaço: usa só um vetor de tamanho capacidade+1
    vector<double> dp(capacidade + 1, 0.0);

    for (auto item : itens) {
        for (int w = capacidade; w >= item.peso; w--) {
            dp[w] = max(dp[w], item.valor + dp[w - item.peso]);
        }
    }
    return dp[capacidade];
}

int Knapsack::readData(vector<Item>& itens) {
    int n;
    double w_input;
    if (!(cin >> n >> w_input)) return 0;
        int capacidade = (int)w_input;

        itens.clear();
        itens.reserve(n);

    for (int i = 0; i < n; i++) {
        double v, p_input;
        cin >> v >> p_input;
        itens.push_back( Item(i+1, (int)p_input, v) );
    }
    return capacidade;
}
