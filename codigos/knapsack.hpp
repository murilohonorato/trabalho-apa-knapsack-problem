#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int id;
    double valor;
    double peso;
    double razao; //valor/peso

    Item(int id, double p, double v) : id(id), peso(p), valor(v) { //Construtor
        if (p>0) razao = v/p;
        else razao=0;
    }
};

namespace KnapsackSolver {
    double fracionaria(vector<Item>& itens, double capacidade); //mochila fracionária
    double binaria(vector<Item>& itens, double capacidade); //mochila 0/1
    void printItens(const vector<Item>& itens);

    //Funções auxiliares
    int compararRazao(const Item& a, const Item& b);
    void imprimirPasso(const Item& item, double peso_usado, double valor_pego, double restante, int tipo);
    double binariaRecursiva(const vector<Item>& itens, double capacidade, int index);
}

#endif
