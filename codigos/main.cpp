#include <bits/stdc++.h>
#include <time.h>
#include "knapsack.hpp"
using namespace std;
using namespace KnapsackSolver;

double executarFracionaria(vector<Item>& itens, int capacidade) {
    clock_t inicio_frac = clock();
    double val_frac = fracionaria(itens, capacidade);
    clock_t fim_frac = clock();
    double tempo_frac = (double)(fim_frac - inicio_frac) / CLOCKS_PER_SEC;
    
    printf(">> Valor Total (Fracionaria): %.2lf (%.4lf segundos)\n", val_frac, tempo_frac);
    return val_frac;
}

double executarBinariaRecursiva(vector<Item> itens, int capacidade) {
    double val_bin = -1;
    if (itens.size() <= 44) {
        clock_t inicio_bin = clock();
        val_bin = binaria(itens, capacidade);
        clock_t fim_bin = clock();
        double tempo_bin = (double)(fim_bin - inicio_bin) / CLOCKS_PER_SEC;
        printf(">> Valor Ótimo Binária (Recursiva): %.2lf (%.4lf segundos)\n", val_bin, tempo_bin);

    } else printf(">> Valor Ótimo Binária (Recursiva): [SKIPPED - Entrada muito grande para força bruta]\n");
    return val_bin;
}

double executarBinariaDP(const vector<Item>& itens, int capacidade) {
    clock_t inicio_dp = clock();
    double val_bin_dp = binariaDP(itens, capacidade);
    clock_t fim_dp = clock();
    double tempo_dp = (double)(fim_dp - inicio_dp) / CLOCKS_PER_SEC;


    printf(">> Valor Ótimo Binária (DP): %.2lf (%.4lf segundos)\n\n", val_bin_dp, tempo_dp);
    return val_bin_dp;
}

void imprimirConclusao(double val_frac, double val_bin, double val_dp) {
    printf("Conclusão\n");
    printf("- Valor Fracionário (Guloso): %.2lf\n", val_frac);
    
    if (val_bin != -1) printf("- Valor Binária (Recursiva): %.2lf\n", val_bin);
    else printf("- Valor Binária (Recursiva): [N/A]\n");
        
    printf("- Valor Binária (DP): %.2lf\n", val_dp);
    
    if (val_bin != -1) printf("Diferença Fracionário vs Binário: %.2lf a mais permitindo frações.\n", (val_frac - val_bin));
    else printf("Diferença Fracionário vs Binário (DP): %.2lf a mais permitindo frações.\n", (val_frac - val_dp));
    printf("-----------------------------\n");
}

int main() {
    vector<Item> itens;
    int capacidade_total = readData(itens);
    cout << "Demonstração: Mochila Fracionária vs Mochila Binária\n";
    printf("Itens: %ld | Capacidade: %d\n\n", itens.size(), capacidade_total);
    //printItens(itens);
    vector<Item> itens_copy = itens;




    //Resolução Fracionária
    double val_frac = executarFracionaria(itens, capacidade_total);

    //Resolução Binária (Recursiva)
    double val_bin = executarBinariaRecursiva(itens_copy, capacidade_total);

    //Resolução Binária (DP)
    double val_dp = executarBinariaDP(itens_copy, capacidade_total);

    //Conclusão
    imprimirConclusao(val_frac, val_bin, val_dp);

    return 0;
}
