#include <bits/stdc++.h>
#define ff first
#define ss second
#define ii pair<int, int>
using namespace std;

// Tamanho maximo de V ou W
const int N = 1e4 + 10;

// Valor maior que (10⁴)²
#define INF 1e8 + 100

// Memoizacao
// Note que está indexada a partir de zero para evitar
// Fazer o memset(), no final, subtrai-se um por causa desse offset
int memo[N][N];

// Valores
int v[N];
// Pesos
int w[N];

int m,n;

// Algoritmo de knapsack
// Inline para aumentar a eficiencia do codigo

inline int knapsack(int p, int ci){
 
    if(p == n and ci < 0)
        return -INF;

    // Retorna 1 para evitar uso de memset()

    if(p == n and ci >= 0)
        return 1;

    if(ci < 0)
        return -INF;
    if(ci == 0)
        return 1;

    int * ans = &memo[p][ci];

    // Se resposta já está calculada seu valor é maior que 0

    if(*ans != 0)
        return *ans;

    // Escolha entre pegar ou não pegar elemento atual

    *ans = max( knapsack(p + 1, ci - w[p]) + v[p], 
                knapsack(p + 1, ci)               );

    return *ans;
}

int main(){
    
    scanf("%d %d", &n,&m);

    for(int i = 0; i < n; i++)
        scanf("%d", v + i);

    for(int i = 0; i < n; i++)
        scanf("%d", w + i);

    // Subtração por 1 para evitar o offset

    printf("%d\n",knapsack(0, m) - 1);

}