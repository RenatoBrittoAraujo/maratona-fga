#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;

int pesos[N], valores[N];

int n;

int memo[N][N];

int knapsack(int i, int p){

	if(i > n or p <= 0)
		return 0;

	int * ans = &memo[i][p];

	if(*ans != -1)
		return *ans;

	if(pesos[i] > p)
		return *ans = knapsack(i + 1, p);

	return *ans = max(knapsack(i + 1, p),
					  knapsack(i + 1, p - pesos[i]) + valores[i]);

}

int main(){

	int peso;

	cout<<"Numero de itens: ";
	cin>>n;

	cout<<"Agora para cada item, seu peso e valor:\n";
	for(int i = 0; i < n; i++)
		cin>>pesos[i]>>valores[i];

	memset(memo, -1, sizeof memo);

	while(1){

		cout<<"Digite o peso da mochila: ";
		cin>>peso;
		cout<<"Valor máximo: "<<knapsack(0, peso)<<endl;

	}

}

