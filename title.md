# Projeto de Análise de Algoritmos (APA)
## Tema: Algoritmos Gulosos - Mochila Fracionária

Este projeto implementa e compara soluções para o problema da Mochila (Knapsack Problem). O foco principal é demonstrar a aplicação de **Algoritmos Gulosos** na versão **Fracionária** do problema e contrastá-la com a versão **Inteira (0/1)**.

---

## 🏆 Enunciado do Problema (Estilo Maratona)

### O Tesouro do Explorador

Você é um explorador que acabou de descobrir uma câmara secreta cheia de tesouros antigos! No entanto, sua mochila tem uma capacidade de carga limitada `W` (em kg) e você não pode carregar tudo.

Diferente de outros exploradores que só podem levar itens inteiros (como estátuas ou coroas), você possui ferramentas especiais que permitem **cortar ou dividir** os itens (como barras de ouro, sacos de especiarias ou pó de diamante) sem perder o valor proporcional.

Sua missão é selecionar partes dos itens disponíveis para **maximizar o valor total** que você pode carregar em sua mochila.

### Entrada
A entrada é composta por:
1. Um número inteiro `N` representando o número de itens disponíveis.
2. Um número real `W` representando a capacidade máxima da mochila.
3. `N` linhas, cada uma contendo dois números reais:
   - `v_i`: O valor total do i-ésimo item.
   - `p_i`: O peso total do i-ésimo item.

### Saída
Um único número real representando o valor máximo que pode ser carregado na mochila.

### Exemplo
**Entrada:**
```text
3 50
60 10
100 20
120 30
```

**Saída:**
```text
240.00
```

**Explicação:**
- Item 1: Valor 60 / Peso 10 = Razão 6.0
- Item 2: Valor 100 / Peso 20 = Razão 5.0
- Item 3: Valor 120 / Peso 30 = Razão 4.0
- Estratégia Gulosa (Pega os de maior razão primeiro):
  1. Leva todo o Item 1 (Peso 10, Valor 60). Resta capacidade 40.
  2. Leva todo o Item 2 (Peso 20, Valor 100). Resta capacidade 20.
  3. O Item 3 pesa 30, mas só cabem 20. Leva-se 20/30 (66.6%) do Item 3.
     Valor levado do Item 3: 120 * (20/30) = 80.
  - Total: 60 + 100 + 80 = 240.

*(Nota: Na versão 0/1 [onde não se pode dividir], você só poderia levar os itens 2 e 3 para um total de 220, ou 1 e 2 para 160. A versão fracionária permite um aproveitamento melhor.)*

---

## 🛠️ Estrutura do Projeto

- `codigos/`: Contém a implementação em C++.
  - `main.cpp`: Código principal que executa a simulação.
  - `knapsack.cpp` / `knapsack.hpp`: Implementação dos algoritmos.
