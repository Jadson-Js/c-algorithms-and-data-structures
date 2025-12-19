# 🔍 Algoritmo de Busca Binária em C (Binary Search)

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Algorithms](https://img.shields.io/badge/Algorithms-CS-red?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)

## 📖 Sobre o Projeto

Este projeto é uma implementação clássica e didática do algoritmo de **Busca Binária** (Binary Search) escrito em linguagem **C**.

O objetivo deste código não é apenas encontrar um número em uma lista, mas demonstrar visualmente como a estratégia de **"Dividir para Conquistar"** funciona. Ao contrário de uma busca linear (que verifica número por número), nosso algoritmo corta o problema pela metade a cada interação, tornando a busca extremamente eficiente em grandes conjuntos de dados.

O programa foi desenhado para mostrar no console o "caminho" que o algoritmo percorre (se ele está indo para valores mais altos ou mais baixos) até encontrar o alvo.

---

## 🧠 O que aprendemos: Por baixo do capô

Aqui explicamos os conceitos de Ciência da Computação aplicados neste código:

### 1. Complexidade Logarítmica $O(\log n)$

A mágica da busca binária é a eficiência.

- **Busca Linear:** Se tivéssemos uma lista de 128 números, no pior caso, teríamos que fazer **128 comparações**.
- **Nossa Busca Binária:** Com 128 números, fazemos no máximo **7 comparações** ($2^7 = 128$).

### 2. A Lógica dos Ponteiros (`low`, `high`, `mid`)

O algoritmo utiliza dois índices para delimitar a área de busca:

- `low`: O início da fatia atual da lista.
- `high`: O final da fatia atual.
- `mid`: O elemento central, calculado por `(high + low) / 2`.

A cada loop, verificamos se o alvo é maior ou menor que o `mid`. Dependendo do resultado, descartamos **metade** da lista inteira ajustando o `low` ou o `high`.

### 3. Cálculos Dinâmicos em C

No código, utilizamos uma técnica robusta para calcular o tamanho do array dinamicamente, sem precisar "chutar" o número de elementos:

```c
const int list_size = (sizeof(list) / sizeof(list[0]));
```
