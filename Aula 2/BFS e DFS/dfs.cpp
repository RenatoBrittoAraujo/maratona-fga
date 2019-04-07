#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> lista[N];

bool visitados[N];

void dfs(int vertice){

	visitados[vertice] = 1; // Marca como visitado o vertice

	for(int i = 0; i < lista[vertice].size(); i++){ // Para cada vizinho
		
		if(!visitados[lista[vertice][i]]) // Se não vistado
			dfs(lista[vertice][i]); // Ja visita ele de cara

	}

}


int main(){

	int v,e;
	cin>>v>>e; // V = vertices, E = (edges) arestas

	for(int i = 0; i < e; i++){

		int a,b;

		cin>>a>>b;

		lista[a].push_back(b); // Note: grafo não-direcionado
		lista[b].push_back(a);

	}
	
	dfs(0); // Rodo o algoritmo em qualquer vertice pra testar

	bool estaConectado = true;

	for(int i = 0; i < v; i++)
		if(!visitados[i])
			estaConectado = false; // Se algum vertice não foi visitado durante a execução
			// Logo ele não está conectado com o resto

	cout<<(estaConectado?"Grafo conexo\n":"Grafo disconexo\n");

}
