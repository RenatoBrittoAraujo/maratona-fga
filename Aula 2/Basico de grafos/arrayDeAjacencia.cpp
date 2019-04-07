#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

// Array bidimensional para guadar relações entre pares
// de vertices, complexidade de memória = O(N*N)
bool grafo[N][N];

// se lista[i][j] = 0, não existe conexão entre vertices
// se lista[i][j] = 1, exite

int main(){
	
	int v; // verices
	cin>>v;

	int e; // arestas (edges)
	cin>>e;

	for(int i=0; i < e; i++){ // para cada aresta
		
		int a,b;
		cin>>a>>b; // leio a aresta

		grafo[a][b] = 1; // se grafo é direcionado ligo A->B

		//grafo[b][a] = 1; // se grafo é não direcionado, ligo também B->A

	}
	
	// Agora tenho o grafo guardado, posso aplicar algoritmos sobre ele

	for(int i = 0; i < v; i++){

		cout<<"Vertice "<<i<<" se conecta com: ";

		for(int j = 0; j < v; j++){

			if(grafo[i][j])
				cout<<j<<' ';

		}	

		cout<<endl;

	}

}
