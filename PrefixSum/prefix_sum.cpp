#include <bits/stdc++.h> // biblioteca que importa toda a STL

using namespace std; // para acessar algo contido nas bibliotecas
					 // acima sem ter que escrever std:: na frente

const int N = 1e1 + 10; // declara tamanho das arrays, geralmente coloca-se
						// alguns elementos a mais de precaução para evitar
						// segmentation fault (nesse caso, 10 elementos)
						// 1e1 significa 1 vezes 10 elevado a 1, outro exemplo:
						// 2e5 significa 2 vezes 10 elevado a 5

int lista[N] = {1,2,3,1,2,6,2,3,4,6}; // array com 10 elementos
									  // declarada aqui pois não ocupa
							  		  // tempo de execução do código

int pref[N]; // array de soma prefixa
			 // vale lembrar que toda array começa com todos
			 // os elementos zerados, caso você não declare
			 // seus conteudos

int main(){ 

	pref[0] = 0; // essa array é indexada à partir do 1,
				 // por isso o inteiro N tem uma "folga" de + 10
				 // pra poder comportar esses detalhes de codigo

	for(int i = 0; i < 10; i++){

		pref[i + 1] = pref[i] + lista[i]; // elemento i + 1 é igual a soma
										  // do elemento anterior na soma preixla
										  // mais o valor do elemento atual da lista

	}

	int l,r;

	cout<<"Lista\n"; 

	for(int i = 0; i < 10; i++){
		
		cout<<lista[i]<<' '; // printando a lista so de role mesmo :D

	}

	cout<<endl;

	cout<<"Soma dos elementos de l -> r\n";

	cin>>l>>r;

	cout<<pref[r] - pref[l-1]<<endl; // a soma dos elementos de l até r
									 // é a soma geral dos elementos ate r
									 // menos o que vem antes de l, no caso, l - 1 

	return 0;
}


