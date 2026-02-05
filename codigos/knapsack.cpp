#include <bits/stdc++.h>
#include "knapsack.hpp"
using namespace std;

namespace KnapsackSolver {
    
    int compararRazao(const Item& a, const Item& b) { //compara para ordenar decrescente pela razão
        return a.razao > b.razao;
    }

    void printItens(const vector<Item>& itens) {
        cout << "Itens disponíveis:\n";
        cout << "ID - Peso - Valor - Razão (V/P)\n";
        cout << fixed << setprecision(2);
        for (const auto& item : itens) {
            cout << item.id << " - " << item.peso << " - " << item.valor << " - " << item.razao << "\n";
        }
        cout << "-----------------------------\n";
    }

    //Função auxiliar pra impressão
    void imprimirPasso(const Item& item, double peso_usado, double valor_pego, double restante, int tipo) {
        if (tipo == 0) { //Pega tudo
            cout << "Pegou 100% do item " << item.id 
                 << " (Peso: " << peso_usado << ", Valor: " << valor_pego 
                 << "). Capacidade restante: " << restante << "\n";

        } else { //Pega fração
            double fracao = peso_usado / item.peso;
            cout << "Pegou " << (fracao * 100) << "% do item " << item.id 
                 << " (Peso: " << peso_usado << "/" << item.peso 
                 << ", Valor: " << valor_pego 
                 << "). Capacidade restante: 0.00\n";
        }
    }

    double fracionaria(vector<Item>& itens, double capacidade) {
        sort(itens.begin(), itens.end(), compararRazao); //ordena os itens pela razão decrescente

        double valor_total = 0.0;
        double capacidade_atual = capacidade;

        cout << "\nExecução da Mochila Fracionária\n";
        cout << "Capacidade inicial: " << capacidade << "\n";

        for (auto item : itens) {
            if (capacidade_atual <= 0) break;

            if (item.peso <= capacidade_atual) { //pega tudo
                capacidade_atual -= item.peso;
                valor_total += item.valor;
                imprimirPasso(item, item.peso, item.valor, capacidade_atual, 0);
            } else { //pega fração
                double fracao = capacidade_atual/(1.0*item.peso);
                double valor_fracao = item.valor*fracao;
                valor_total += valor_fracao;
                imprimirPasso(item, capacidade_atual, valor_fracao, 0.0, 1);
                capacidade_atual = 0;
            }
        }
        return valor_total;
    }

    double binariaRecursiva(const vector<Item>& itens, double capacidade, int index) {
        if (index == itens.size() || capacidade == 0) return 0;

        if (itens[index].peso > capacidade) return binariaRecursiva(itens, capacidade, index+1); //ignora o item atual

        double incluir = itens[index].valor + binariaRecursiva(itens, capacidade - itens[index].peso, index+1); //inclui o item 
        double nao_incluir = binariaRecursiva(itens, capacidade, index+1); //n inclui o item

        return max(incluir, nao_incluir);
    }

    double binaria(vector<Item>& itens, double capacidade) {
        return binariaRecursiva(itens, capacidade, 0);
    }

}
