# Básico de DP's

Leia o codigo do fibonacci normal e execute, com input de 40 o número de chamadas já é enorme (porque a complexidade é O(2^n))

Agora leia o código do fibonacci com DP, em que o estado de valores já calculados é gurdado e note como o numero de chamadas recursivas cai drásticamente

Esse é o poder da Programação Dinâmica (Dinamic Programming ou DP para os de casa), desenvolvida por Bellman nos anos 50

Ela funciona em problemas em que para definir o valor de estado atual você pode usar informações de estados anteriores (fib(n) = fib(n-1) + fib(n-2)) para definir a solução

Essa habilidade de guardar informações de estados anteriores reduz muito o número de operações que o computador faz para descobrir algum número, porque ao invés de repetir calculos já feitos, ele guarda na memória a solução para estados anteriores

Se você ainda não sabe, qualquer operação recursiva no computador pode ser feita iteravamente (com loop's for e while) ao invés de chamar uma função que se chama várias vezes, porém é muito mais legível (e debugável) a escrita de um código recursivo e muitas vezes (não todas) mais rápido, por isso normalmente se utiliza funções recursivas na programação dinâmica

Vamos analisar outro exemplo: o problema das moedas (Coin Change problem)

Imagina que eu queira te dar um troco para um certo valor N usando um conjunto de moedas de várias denominações de forma que o número de moedas que eu use seja o menor possível.

Existem duas possibilidades para resolver:
- A solução gulosa que resolve casos específicos
- A solução de programção dinâmica que resolve qualquer caso

Vamos pensar: se meu conjunto de moedas for as denominações {1, 5}, para um troco de valor N eu te devolvo N/5 + N%5 moedas. Caso N = 12, o menor número de moedas que eu uso seria 4, 2 de 5 mais 2 de 1

O algoritmo guloso seria pegar o N atual, subtrair dele a menor moeda possível que cabe em N, subtrair N -= valor_da_moeda e repetir o processo até que o N == 0 ou não caiba mais nenhuma moeda 

Mas e se o conjunto fosse {1, 3, 4} e N = 6?

Pegariamos 4 que é a maior moeda que cabe em 6, subtrairiamos e teriamos 2, depois pegariamos 2 moedas de 1 até completar 6, totalizando 3 moedas

Porém, com 2 moedas de 3, teriamos 6

O nosso algoritmo guloso falha para esse conjunto de moedas em alguns casos, e é ai que a DP pode nos ajudar

Poderiamos testar todos os casos possíveis para distribuição de moedas até encontrar o menor conjunto que resolve o problema.

Temos apenas um parâmetro para esse tipo de recursão: O valor que falta para resolver. Podemos guardar o valor dos casos anteriores até encontrar o mínimo.

Veja os códigos para comparar as duas soluções.

Agora que você tem uma noção melhor de uma DP vamos mostrar mais um caso

Imagine que vocẽ vai roubar uma joaleria, você tem uma mochila para carregar os itens roubados que comporta, no máximo, uma peso W (weigth). Cada item que você pode pegar tem um peso e um valor (em reais, você não tá roubando atoa). Para um dado W da mochila e um conjunto de itens, qual é máximo valor que você pode levar?

Novamente, a DP pode ajudar a gente a resover esse caso. Alias esse problema é bastante conhecido e chamado de Problema da Mochila, ou Knapsack.

Dessa vez, a gente pode escrever uma DP assim: para cada item a gente escolhe pegar ou não pegar, e pro item seguinte faz o mesmo até testar todos os itens e ver qual é o maior valor que a gente consegue no final. Dado um W qualquer, nos podemos calcular uma vez qual é o melhor valor na posição atual de itens a analisar e guardar isso (O subproblema para um indice na lista de itens e o peso restante na mochila).

Veja o código

Como exercício, tente adaptar esse código caso você possa pegar o mesmo item varias vezes.

Com esses três exemplos, possível definir uma estrutura básica da DP:

- Parâmetros da DP -> São os valores que representam o caso atual do problema (no fibonacci, o numero de fibonnaci do estado atual, no caso do coin change, o troco atual e no knapsack, o item atual + o peso que resta).
- Casos de parada/Casos base -> É a saída da recursão, o estado em que a solução é trivial ou inválida (no caso de inválida, retornar erro ou valor para representar solução inválida como o INF no coin change).
- Operação sobre estado atual -> no fibonacci, pegar a soma de fib(n-1) + fib(n-2), no caso coin change, o troco com o menor numero de moedas para dado valor e no caso do knapsack, pegar um item ou não pegar.

As DP's apresentadas são clássicas, muito bem conhecidas, dificilmente você encontra elas em competições. Você vai ter que criar sua própria DP na maioria das questões e para isso é necessário treinamento e entender como uma DP funciona. Também a criatividade de descobrir a manha da questão.

Existem várias otimzações de DP (como a máscara de bits) porém elas são complicadas e eu não conheço muito bem, mas explicarei-as no futuro.

Execícios para treinar o aprendido (URI):
- Fibonacci DP: https://www.urionlinejudge.com.br/judge/pt/problems/view/1176
- Problema das Moedas: https://www.urionlinejudge.com.br/judge/pt/problems/view/1034
- Knapsack: https://www.urionlinejudge.com.br/judge/pt/problems/view/1288

Alguns exercícios (mais difíceis):
- SPOJ https://www.spoj.com/problems/MST1/
- UVa https://uva.onlinejudge.org/external/1/p100.pdf
- CodeForces https://codeforces.com/contest/368/problem/B
- UVa https://uva.onlinejudge.org/external/8/p825.pdf
- CodeForces https://codeforces.com/contest/359/problem/B
