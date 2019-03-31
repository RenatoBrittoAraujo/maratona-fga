#include <bits/stdc++.h>

using namespace std;

const int N = 10 + 10;

int a[N] = {1,5,2,4,8,5,3,2,3};

bool busca(int v){
	
	int hi = 9; // Valor máximo da array inicialmente, esse é o numero que 
				// aponta pro maior valor dentro do nosso intervalo

	int lo = 0; // Valor minimo da array inicialmente, esse é o numero que
				// aponta pro menor valor dentro do nosso invervalo

	int mid = (hi + lo) / 2;

	while(!(lo + 1 == hi)){

		mid = (hi + lo) / 2; // Elemento central entre hi e lo (divisão inteira)

		if(a[mid] == v)return true; // Faz a comparação, é o valor, logo retorna verdadeiro

		// Se chegou aqui, não estamos no elemtno que queremos, então...

		if(a[mid] > v)hi = mid; // Se o elemento no indice mid for menor que v,
								// então v está pra trás de mid, logo hi = mid

		else lo = mid; // Se o elemento for maior que mid, então
					   // v está para frente de v
	}

	// O espaço de busca é cortado toda vez em dois.
	// Por isso, n vira n/2 depois n/4, n/8 ... até convergir pra n/(2^(x)) = 1,
	// log2(N) = x, por isso a complexidade desse algoritmo é log(n)

	return false;

}


int main(){
	
	sort(a, a + 9); // Ordena os elementos da array em O(N*log(N))

	while(1){

		int v;

		cout<<"Valor a ser buscado na array\n";

		cin>>v;

		bool resposta  = busca(v);
	
		cout<<(resposta?"Encontrado":"Não encontrado")<<endl; 

		/*
			Esse '?' é o operador condicional 
			Antes dele vem um pergunta do tipo booleana
			Se a resposta dessa pergunta é true, ele retorna o elemento a esqueda do
			':', caso contrario retorna o elemento a direta.

			Os dois elementos tem que ser do mesmo tipo, por exemplo, os dois
			nesse caso são char[].
		*/
	}
}
	



