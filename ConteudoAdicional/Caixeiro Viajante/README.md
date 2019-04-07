# Algoritmo de Caixeiro Viajante (Travelling Salesman Problem)

Dado um grafo com pesos nas arestas e um vertice inicial, qual é o menor caminho pelo qual você visita todos os vértices com o menor percursso possível e volta para o primeiro ponto

O caixeiro viajante serve para resolver esse problema

Tem dois flavors para a solução desse problema

- Indicando apenas o valor do menor caminho
- Mostando todo o caminho

Esse problema é resolvido com uma DP e uma array de adjacência, com bitmask(máscara de bits)

Esse algoritmo tem complexidade minima O(v!), v = vertices

Veja o código

O codigo é facilmente adaptável para apenas retornar o valor do menor caminho e não a ordem dos vértices
