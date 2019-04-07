#include <bits/stdc++.h>

using namespace std;

// Algoritmo de kruskall encontra a árvore geradora minima de um grafo
// Na maneira mais humana de falar, imagina um grafo
// Se você precisa encontrar a minimo de arestas que conectam um grafo de
// forma a soma das arestas seja minima
// O algoritmo de kruskall faz isso pra você com complexiadade O(E * log(V)),
// E = arestas (edges), V = vertices. ->E porque você itera por toda lista de 
// E arestas e ->log(V) porque essa é complexidade amorizada do DSU

const int N = 1e5 + 10;

//// DISJOINT SET UNION
int p[N];

int find(int u){
	if(u == p[u])return u;
	else return p[u] = find(p[u]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);
	if(a > b)swap(a,b);
	p[b] = a; // Não há necessidade de fazer o dsu por ordem de tamanho, porem é menos eficiente
}

bool same(int a, int b){return find(a) == find(b);}
//// FIM DO DSU

// O kruskall é facil de entender quando você entende que 
// estamos guardando as aresta e não os nós do vertice
// e que estamos conectando nós deconexos até formar 
// um grafo conectado

// Declara um vetor de par de inteiros sendo igual ao simbolo 'ii'
using ii = pair<int,int>;

// Lista de todas as arestas disponiveis
// Estrutura de cada aresta é o tamanho dela e um par de nós que ela conecta
// Por isso um par de (inteiro, par de (inteiros))
vector<pair<int,ii>> listaDeArestas, arestasEscolhidas;

int main(){
	int V, E; // vertices e arestas (Edges, por isso E)
	cin>>V>>E;
	
	for(int i = 0; i < V; i++)p[i] = i; // Inicializa DSU

	for(int i = 0; i < E; i++){
		
		int a,b,c;
		cin>>a>>b>>c;

		// C = tamanho da aresta
		// A <-> B = nos ligados por aresta

		listaDeArestas.push_back( make_pair( c, make_pair(a, b) ) );

	}

	sort(listaDeArestas.begin(), listaDeArestas.end());
	// Organiza as arestas da menor pra maior

	for(int i = 0; i < listaDeArestas.size(); i++){

		ii conectados = listaDeArestas[i].second;

		if(!same(conectados.first, conectados.second)){
			
			join(conectados.first, conectados.second);

			arestasEscolhidas.push_back(listaDeArestas[i]);

		}
	
	}

	for(int i = 0; i < arestasEscolhidas.size(); i++){

		cout<<"Aresta escolhida de "<<arestasEscolhidas[i].second.first<<" para "<<arestasEscolhidas[i].second.second<<endl; 

	}

	return 0;
}
