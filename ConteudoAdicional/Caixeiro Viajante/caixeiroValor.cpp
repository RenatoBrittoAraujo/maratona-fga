#include <bits/stdc++.h>
using namespace std;

const int N = 20; // Algoritmo O(n!) portanto n não pode ser muito grande
const int INF = 1000000007;
using ll = long long;

int V, E;
int verticeInicial;

vector<pair<int,int>> grafo[N];

int distancia[N][N];

// Um bfs para definir a menor distância entre vertice u -> v
// Poderiamos usar também o algoritmo de warshall
void dijkstra_distancias(int inicial){

	// Definimos como infinita a distancia de todo vertice ligado ao 'incial'

	for(int i = 0; i < V; i++)
		distancia[inicial][i] = INF;		

	// Criamos uma PQ para os elementos (para impedir a inclusão do mesmo elemento duas vezes)

	priority_queue<int> fila;
	
	fila.push(inicial);

	distancia[inicial][inicial] = 0;

	while(!fila.empty()){ // Enquanto nao fila vazia

		int u = fila.top();

		fila.pop();

		for(auto v: grafo[u]){ // Visitamos seus vizinhos

			// Se a distancia do vertice atual pro vizinho for menor que a do inicial pro vizinho, atualizar

			if(v.first + distancia[inicial][u] < distancia[inicial][v.second]){
				
				distancia[inicial][v.second] = distancia[inicial][u] + v.first;

				fila.push(v.second); // E botar na fila
			}
		}
	}
}

pair<ll, vector<int>> caixeiroViajante(int vertice, ll bitmask){ 
	
	// Input = vertice atual e bitmask representando elementos visitados

	// Se estamos no vertice incial e bitmask NÃO é nula

	if(vertice == verticeInicial and bitmask == (1<<V) - 1){

		// Se bitmask estiver preenchida temos um resultado válido (1<<V - 1 == 2^v - 1)
	
		vector<int> encontrado;
		encontrado.push_back(verticeInicial);
		return make_pair(0, encontrado);
	
	}else if(vertice == verticeInicial and (bitmask>>verticeInicial & 1)){

		// Caso não esteja preenchida, resultado inválido (0 < bitmask < 2^v - 1)
		
		return make_pair((ll)INF*(ll)INF, vector<int>());
	
	}
	
	bitmask = bitmask + (1<<vertice); // Marcamos na bitmask que vertice atual foi visitado

	ll valor = (ll)INF * (ll)INF; // Declaramos valor infinito para caminho atual
	vector<int> caminho; // E declaramos a array de retorno

	for(int i = 0; i < V; i++){ // Para cada vertice ligado ao 'vertice'
		
		// Se não for igual ao próprio vertice e (não foi visito ou liga para o vertice inicial)

		if(i != vertice and (!((bitmask>>i) & 1) or i == verticeInicial)){
				
			// Rodamos o caixeiro viajante recursivamente

			pair<ll, vector<int>> resultado = caixeiroViajante(i, bitmask);	

			// Se o caminho gerado pelo caixeiro for menor menor que o caminho atualmente registrado

			if(resultado.first + distancia[vertice][i] < valor){

				// Tomamos esse caminho como a melhor resposta
	
				valor = resultado.first + distancia[vertice][i];
				caminho = resultado.second;

			}

		}
		
	}

	caminho.push_back(vertice);

	return make_pair(valor, caminho); // Retornando par de vetor caminho + valor do caminho

}

int main(){
	
	cin>>V>>E;

	// Guardando grafo

	cout<<"Digite o numero dr vertices e arestas, depois para cada aresta\n";
	cout<<"a aresta de origem, destino e o peso da aresta\n";

	for(int i = 0; i < E; i++){

		int dist, u, v;

		cin>>u>>v>>dist;

		grafo[u - 1].emplace_back(dist, v - 1); // Emplace_back já faz o par pra você

	}

	cout<<"Formando array de distancias...\n";
	
	cout<<"Distancia do indice na linha para o indice na coluna (-1 = Infinito)\n";


	// Print bonito da tabela de distancias
		
	for(int i = 0; i < V; i++)
		dijkstra_distancias(i);
	
	printf("   ");
	for(int i = 0; i < V; i++)
		printf("%4d ", i + 1);
	cout<<endl;

	printf("   ");
	for(int i = 0; i < V; i++)
		printf("____ ");
	cout<<endl;

	for(int i = 0; i < V; i++){
		printf("%d |", i + 1);
		for(int j = 0; j < V; j++){
			printf("%4d ", (distancia[i][j] == INF? -1 : distancia[i][j])); 
		}
		cout<<endl;
	}
	// Essa parte acima pode ser ignorada

	cout<<"Formar caminho partindo e terminando em qual vertice: ";

	cin>>verticeInicial;

	verticeInicial--;

	// Chamamos a DP no vertice inicial com bitmask zerada

	auto menorCaminho = caixeiroViajante(verticeInicial, 0LL);

	// Se o caminho deu maior que INF, esse caminho passa por arestas notadas como inexistente
	// Portanto não existe

	if(menorCaminho.first >= INF)
	
		cout<<"Não existe caminho do caixeiro viajante no grafo dado\n";
	
	else{ // Mas caso exista, é retornado o par do valor e caminho

		cout<<"Tamanho do percurso do caminho mais curto = "<<menorCaminho.first<<endl;
	
		auto vetor = menorCaminho.second;
		reverse(vetor.begin(), vetor.end());
		
		cout<<"Caminho: ";
		
		for(auto indice: vetor)
			cout<<indice<<' ';
		
		cout<<endl;
	}
}
