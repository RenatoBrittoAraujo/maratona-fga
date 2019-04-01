#include <bits/stdc++.h>

using namespace std;

// Par de (inteiro, par de (inteiro. inteiro))
// o primeiro inteiro significa o peso da aresta
// o segundo e o terceiro representam a ligação do segundo->terceiro 
vector<pair<int, pair<int, int>> grafo;

int main(){

	int v,e;
	cin>>v>>e;

	for(int i = 0; i < e; i++){
		
		int dist, u, v;

		cin>>dist>>u>>v;

		grafo.push_back( make_pair(dist, make_pair(u, v) ) ); // se unidirencional

		grafo.push_back( make_pair(dist, make_pair(v, u) ) ); // se houver ligação de volta tiver o mesmo peso

	}

	// Nesse caso, precisariamo de um algoritmo pra definir os vizinhos
	// de cada vertice, o que fugiria do ponto, entao terminamos aqui

}
