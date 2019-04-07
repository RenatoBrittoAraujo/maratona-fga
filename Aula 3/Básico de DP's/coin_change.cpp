#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7; // Valor "infinito"

int moedas[100];
int numero_de_moedas;

int moedas_guloso(int n){

	int p = numero_de_moedas - 1; // Aponta para posição de moedas mais alta que cabe em N

	int moedas_usadas = 0;

	while(n){ // Enquanto n não é zero

		while(p > 0 and moedas[p] > n)p--; // Enquanto moeda atual for maior que troco

		if(p == 0 and moedas[p] > n)
			return -1; // Caso nem a menor moeda resolva N, retorne -1

		n -= moedas[p];

		moedas_usadas++;

	}
	
	return moedas_usadas;

}

int memo[100000]; // Chave: valor atual de troco, Valor: numero de moedas minimo para resolver problema

int moedas_dp(int n){

	if(n < 0)return INF;
	if(n == 0)return 0;
	
	int * ans = &memo[n]; // para não ter que escrever memo[n] toda vez (traga para vocês diretamente dos finalistas mundiais da UnB)

	if(*ans != -1)return *ans;

	*ans = INF;

	for(int i = 0; i < numero_de_moedas; i++){
		
		*ans = min(*ans, moedas_dp(n - moedas[i]) + 1);

	}

	return *ans;

}

int main(){

	memset(memo, -1, sizeof memo);

 	cout<<"Numero de moedas do conjunto: ";
	cin>>numero_de_moedas;

	cout<<"Agora as moedas: ";
	for(int i = 0; i < numero_de_moedas; i++)
		cin>>moedas[i];

	sort(moedas, moedas + numero_de_moedas);

	while(1){

		int n;
		cout<<"Troco para: ";
		cin>>n;
		cout<<"Solução gulosa = "<<moedas_guloso(n)<<endl;
		cout<<"Solução DP = "<<moedas_dp(n)<<endl;

	}

}
