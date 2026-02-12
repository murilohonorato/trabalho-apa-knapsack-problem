# Estudo e Implementação do Problema da Mochila

Este repositório contém o projeto desenvolvido para a disciplina de **Análise e Projeto de Algoritmos (APA)**, focado no estudo, implementação e análise de performance do Problema da Mochila (*Knapsack Problem*) em suas variantes Fracionária e 0/1.

## 👥 Equipe
- **Caio Wallace Machado Gomes** - [caio.machado@discente.ufg.br](mailto:caio.machado@discente.ufg.br)
- **Eduardo Fraga Pereira** - [eduardofraga@discente.ufg.br](mailto:eduardofraga@discente.ufg.br)
- **Murilo Honorato de Souza** - [murilo.honorato@discente.ufg.br](mailto:murilo.honorato@discente.ufg.br)

## 📋 Visão Geral

O projeto explora diferentes paradigmas de programação para resolver problemas de otimização combinatória:
- **Algoritmo Guloso**: Utilizado para a Mochila Fracionária, garantindo a otimalidade global em tempo loglinear.
- **Força Bruta (Recursivo)**: Implementação pedagógica para a Mochila 0/1, demonstrando a explosão exponencial de complexidade.
- **Programação Dinâmica**: Solução eficiente para a Mochila 0/1 com otimização de espaço para vetor unidimensional (1D).

## 🚀 Destaques Técnicos

- **Alta Performance**: Uso de *Fast I/O* em C++ e reserva estratégica de memória para processar instâncias com até $10^7$ itens.
- **Otimização de Espaço**: Redução da complexidade de espaço da DP de $O(NW)$ para $O(W)$, permitindo a execução em hardware convencional com grandes capacidades (instâncias de até 5 milhões de subproblemas em RAM).
- **Arquitetura POO**: Código estruturado na classe `Knapsack` para garantir modularidade, encapsulamento e separação entre interface (`.hpp`) e implementação (`.cpp`).
- **Automação de Testes**: Pipeline completo com geração de dados em Python e orquestração via Makefile com flags de otimização `-O3`.

## 🛠️ Como Utilizar

### 1. Clonando o Repositório
```bash
git clone https://github.com/murilohonorato/trabalho-apa-knapsack-problem.git
cd trabalho-apa-knapsack-problem
```

### 2. Pré-requisitos
Certifique-se de ter os seguintes componentes instalados:
*   `g++` e `make` (para o código C++)
*   `Python 3.x`, `pandas` e `matplotlib` (para a geração de gráficos e análise visual)

### 3. Compilação
Na raiz do projeto, execute:
```bash
make
```
O executável `main` será gerado dentro da pasta `codigos/`.

### 4. Execução Dinâmica
O Makefile simplifica a execução contra os arquivos da pasta `dados/`:
- Para testar com `dados/input1.txt`: `make 1`
- Para testar com `dados/input5.txt`: `make 5`
- Para testar com `dados/input2.txt`: `make 2`

### 5. Análise Visual e Gráficos
Para atualizar os gráficos de desempenho baseados nos benchmarks coletados:
```bash
cd graficos
python plot_results.py
```
Isso gerará visualizações como `comparativo_geral.png` e `explosao_recursiva.png`.

## 📁 Estrutura do Projeto

- `relatorio-grupo-G.pdf`: Relatório técnico detalhado em formato SBC (LaTeX).
- `perguntas-grupo-G.txt`: Questionário de revisão com gabarito sobre o tema.
- `codigos/`: Implementação core em C++ (`knapsack.hpp`, `knapsack.cpp`, `main.cpp`).
- `graficos/`: Scripts de plotagem, imagens geradas e o `performance_report.md`.
- `dados/`: Conjunto de casos de teste (`input*.txt`) e o script `generate.py`.
- `README.md`: Documentação principal do projeto.

## 📊 Resultados e Benchmarks

Abaixo, apresentamos o comparativo completo de desempenho coletado durante os testes:

| N (Itens) | Capacidade | Guloso | Rec. (Binário) | DP (Binário) |
| :--- | :--- | :--- | :--- | :--- |
| 10 | 50 | < 0.0001s | 0.0000s | < 0.0001s |
| 20 | 100 | < 0.0001s | 0.0001s | < 0.0001s |
| 30 | 150 | < 0.0001s | 0.0065s | < 0.0001s |
| 40 | 200 | < 0.0001s | 2.5894s | < 0.0001s |
| 50 | 250 | < 0.0001s | ~44 min* | < 0.0001s |
| 60 | 300 | < 0.0001s | ~31 dias* | < 0.0001s |
| 70 | 350 | < 0.0001s | ~88 anos* | < 0.0001s |
| 80 | 400 | < 0.0001s | ~90 mil anos* | < 0.0001s |
| 90 | 450 | < 0.0001s | ~92 milh anos* | < 0.0001s |
| 100 | 500 | < 0.0001s | ~94 bi anos* | < 0.0001s |
| 1.000 | 2.000 | 0.0001s | - | 0.0010s |
| 10.000 | 10.000 | 0.0005s | - | 0.0317s |
| 100.000 | 50.000 | 0.0061s | - | 1.5853s |
| 1.000.000 | 500.000 | 0.0742s | - | 147.60s |
| 10.000.000 | 5.000.000 | 0.8935s | - | ~4.1 h* |

*\*Valores estimados com base na complexidade assintótica $O(2^N)$.*

## 🛠️ Tecnologias Utilizadas
- **C++**: Implementação de alta performance dos algoritmos de otimização.
- **Python**: Automação da geração de cargas de teste e análise visual (Matplotlib & Pandas).
- **Makefile**: Gestão de build e orquestração de testes automatizados.
- **LaTeX (Beamer & SBC)**: Produção da documentação técnica e material visual do seminário.
