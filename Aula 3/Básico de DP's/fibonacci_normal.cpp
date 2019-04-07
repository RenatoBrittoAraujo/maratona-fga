#include <bits/stdc++.h>
using namespace std;

using ll = long long; // Macro para não escrever 'long long' toda vez para declarar o tipo

ll chamadas;

ll fibonacci(ll n){

	chamadas++;

	if(n == 0)return 0;
	if(n == 1)return 1;

	return fibonacci(n-1) + fibonacci(n-2);

}

int main(){

	cout<<"Note como o algoritmo demora para inputs por volta de 40\n";

	while(1){
		
		ll valor;
		chamadas = 0;
		cin>>valor;
		cout<<"Fibonacci("<<valor<<") = "<<fibonacci(valor)<<endl;
		cout<<"Número de chamadas da função: "<<chamadas<<endl;

	}

}


