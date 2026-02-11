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

class Knapsack {
    private:
        vector<Item> itens;
        int capacidade;

        static bool compararRazao(Item a, Item b);
        void imprimirPasso(Item item, double peso_usado, double valor_pego, double restante, int tipo);
        double binariaRecursiva(int capacidade, int index);

    public:
        Knapsack(const vector<Item>& i, int c) : itens(i), capacidade(c) {} //construtor

        double fracionaria(); //mochila fracionária
        double binaria();     //mochila 0/1 recursiva
        double binariaDP();   //mochila 0/1 DP

        void printItens();

        static int readData(vector<Item>& itens_out);
};

#endif
