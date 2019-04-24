#include <bits/stdc++.h>
using namespace std;

using ll = long long; // Macro para não escrever 'long long' toda vez para declarar o tipo

ll mod = 1e9 + 7;

ll chamadas;

ll memo[100000000]; // Guarda informações sobre estados já calculados

ll fibonacci(ll n){

	chamadas++;

	if(memo[n]!=-1)return memo[n];

	return memo[n] = (fibonacci(n-1) + fibonacci(n-2)) % mod;

}

int main(){

	cout<<"Agora ele demora muito menos e o número de chamadas cai drasticamente\n";

	memset(memo, -1, sizeof memo); // Definindo todos os elementos de memo como '-1'

	memo[0] = 0;
	memo[1] = 1; // Casos base

	while(1){
		
		ll valor;
		chamadas = 0;
		cin>>valor;
		cout<<"Fibonacci("<<valor<<") = "<<fibonacci(valor)<<endl;
		cout<<"Número de chamadas da função: "<<chamadas<<endl;

	}

}


