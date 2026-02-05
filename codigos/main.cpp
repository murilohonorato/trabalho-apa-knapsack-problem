#include <bits/stdc++.h>
#include "knapsack.hpp"
using namespace std;
using namespace KnapsackSolver;

int main() {
    double capacidade_total = 50.0;
    vector<Item> itens;
    itens.emplace_back(1, 10.0, 60.0);
    itens.emplace_back(2, 20.0, 100.0);
    itens.emplace_back(3, 30.0, 120.0);

    cout << "Demonstração: Mochila Fracionária vs Mochila Binária\n\n";

    printItens(itens);

    vector<Item> itens_copy = itens;

    //Resolução fracionária
    double val_frac = fracionaria(itens, capacidade_total);
    cout << ">> Valor Total (Fracionaria): " << val_frac << "\n";
    cout << "-----------------------------\n\n";

    //Resolução binária
    cout << "Execução da Mochila Binária\n";
    double val_bin = binaria(itens_copy, capacidade_total);
    cout << "Valor otimo Binária: " << val_bin << "\n";
    cout << "-----------------------------\n\n";

    cout << "Conclusão\n";
    cout << fixed << setprecision(2);
    cout << "- Valor Fracionário (Guloso): " << val_frac << "\n";
    cout << "- Valor Binária (Otimo):          " << val_bin << "\n";
    cout << "Diferenca: " << (val_frac - val_bin) << " a mais permitindo frações.\n";
    cout << "-----------------------------\n";

    return 0;
}
