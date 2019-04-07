#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> grafo[N];
bool visitados[N];

void bfs(int inicial){

	queue<int> fila; // Cria um fila, o primeiro elemento que entra é o primeiro que sai
	// Inversamente, o ultimo que entra é o ultimo que sai
	fila.push(inicial);
	visitados[inicial] = true;

	while(!fila.empty()){ // Enquanto a fila não está vazia

		int vertice = fila.front(); // Pega o elemento na frente da fila
		fila.pop(); // Remove o elemento da fila

		for(auto outroV: grafo[vertice]){ // Para cada vizinho de vertice
			
			if(!visitados[outroV]){ // Se ele não foi visitado

				visitados[outroV] = true; // Marca como visitado

				fila.push(outroV); // E bota ele na fila

			}

		}

	}
}

int main(){

	int v,e;
	cin>>v>>e;

	for(int i = 0; i < e; i++){
	
		int a,b;
		cin>>a>>b;

		grafo[a].push_back(b);
		grafo[b].push_back(a);

	}

	bfs(0);

	bool estaConectado = true;

	for(int i = 0; i < v; i++)
		if(!visitados[i])
			estaConectado = false;

	cout<<(estaConectado?"Grafo conexo\n":"Grafo desconexo\n");
}
