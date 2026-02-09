# Projeto de Análise de Algoritmos (APA)
## Tema: Algoritmos Gulosos - Mochila Fracionária

O enunciado  abaixo utiliza o modelo de escrita de exercícios de Programação Competitiva com o objetivo de tornar a lógica da **Mochila Fracionária** mais intuitiva e demonstrar a eficiência da abordagem gulosa em contraste com a versão inteira (0/1).

---

### Problema: Otimização de Carga (Knapsack Fracionário)

Dada uma mochila com capacidade de carga total $W$ e um conjunto de $N$ itens, cada um com um valor $v_i$ e um peso $p_i$, determine o valor máximo que pode ser transportado.

Diferente da versão clássica 0/1, neste problema é permitido levar frações de cada item. Se você decidir levar uma fração $x_i$ ($0 \le x_i \le 1$) do item $i$, o peso ocupado será $x_i \cdot p_i$ e o valor obtido será $x_i \cdot v_i$.

O objetivo é preencher a mochila de forma a maximizar o valor total acumulado, respeitando o limite $W$.

#### Entrada

A primeira linha da entrada contém um inteiro $N$ ($1 \le N \le 10^7$) e um valor real $W$ ($0 \le W \le 10^9$), representando o número de itens e a capacidade da mochila, respectivamente.

As $N$ linhas seguintes contêm, cada uma, dois valores reais $v_i$ e $p_i$ ($0 \le v_i, p_i \le 10^9$), indicando o valor total e o peso total do item $i$.

#### Saída

A saída deve consistir em uma única linha contendo o valor máximo que pode ser carregado, formatado com duas casas decimais.

#### Exemplos

| Entrada | Saída |
| :--- | :--- |
| 3 50.0<br>60.0 10.0<br>100.0 20.0<br>120.0 30.0 | 240.00 |

**Explicação do exemplo:**
Para maximizar o valor, utiliza-se a estratégia gulosa baseada na densidade de valor (razão $v/p$):
1. Item 1: razão 6.0 ($60/10$). Levamos o item completo (10kg, Valor 60). Espaço restante: 40kg.
2. Item 2: razão 5.0 ($100/20$). Levamos o item completo (20kg, Valor 100). Espaço restante: 20kg.
3. Item 3: razão 4.0 ($120/30$). Como restam apenas 20kg de espaço, levamos $2/3$ do item (20kg, Valor 80). Espaço restante: 0kg.
**Valor Total:** $60 + 100 + 80 = 240.00$.

---