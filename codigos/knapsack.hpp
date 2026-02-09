#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int id;
    double valor;
    int peso;
    double razao; //valor/peso

    Item(int id, int p, double v) : id(id), valor(v), peso(p) { //Construtor
        if (p>0) razao = v/(double)p;
        else razao=0;
    }
};

namespace KnapsackSolver {
    double fracionaria(vector<Item>& itens, int capacidade); //mochila fracionária
    double binaria(vector<Item>& itens, int capacidade); //mochila 0/1
    void printItens(const vector<Item>& itens);

    //Funções auxiliares
    int readData(vector<Item>& itens);
    int compararRazao(const Item& a, const Item& b);
    void imprimirPasso(const Item& item, double peso_usado, double valor_pego, double restante, int tipo);
    double binariaRecursiva(const vector<Item>& itens, int capacidade, int index);
    double binariaDP(const vector<Item>& itens, int capacidade);
}

#endif
