# Problema da Mochila (Knapsack Problem)

Este projeto implementa soluções para o Problema da Mochila (Fracionária e Binária) como parte da disciplina de Análise e Projeto de Algoritmos (APA).

## 🚀 Como Utilizar

### 1. Pré-requisitos
Certifique-se de ter o `g++` e o `make` instalados em seu sistema.

### 2. Clonando o Repositório
```bash
git clone https://github.com/murilohonorato/trabalho-apa-knapsack-problem.git
cd trabalho-apa-knapsack-problem
```

### 3. Compilação
Para compilar o projeto, utilize o comando `make` na raiz do diretório:
```bash
make
```
Isso gerará o executável `exec` dentro da pasta `codigos/`.

### 4. Execução
O Makefile possui regras dinâmicas para facilitar a execução dos arquivos de entrada localizados na pasta `dados/`. Utilize o sufixo do arquivo `input`.

- Para executar com `dados/input1.txt`:
  ```bash
  make 1
  ```
- Para executar com `dados/input1_2.txt`:
  ```bash
  make 1_2
  ```
- Para executar com `dados/input5.txt`:
  ```bash
  make 5
  ```

## 📁 Estrutura do Projeto

- `codigos/`: Contém os arquivos-fonte C++ (`main.cpp`, `knapsack.cpp`, `knapsack.hpp`) e o binário gerado.
- `dados/`: Arquivos de entrada (`input*.txt`) e script de geração.
- `graficos/`: Relatórios de desempenho e gráficos relacionados.
- `Makefile`: Automação de compilação e execução.

## 🛠️ Tecnologias Utilizadas
- C++
- Makefile