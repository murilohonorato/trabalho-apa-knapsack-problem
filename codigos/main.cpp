#include <bits/stdc++.h>
#include "knapsack.hpp"
using namespace std;

int main() {
    double cap = 50.0;
    vector<Item> itens;
    itens.push_back(1, 10.0, 60.0);
    itens.push_back(2, 20.0, 100.0);
    itens.push_back(3, 30.0, 120.0);

    cout << "Demonstração: Mochila Fracionaria (Guloso) vs Mochila 0/1\n\n";



    cout << "\nConclusão\n";
    cout << "Diferença: " << "..." << " a mais permitindo frações.\n";

    return 0;
}
