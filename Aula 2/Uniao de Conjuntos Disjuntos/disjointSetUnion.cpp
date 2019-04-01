#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int pai[N];
int tamanho[N];
int n;

// Grupos disjuntos à partir de [0,n)

// Inicializa DSU
// O pai de cada elemento é o próprio elemento
// O tamanho de cada grupo é, portanto, 1
void inicializar(){
	for(int i = 0; i < n; i++){
		pai[i] = i;
		tamanho[i] = 1;	
	}
}

// Operação find
// Encontra "pai" de elemento
// Complexidade dessa operacão é O(log(n)) amortizada
// Mesmo no pior dos casos podendo ser linear (N)
// O pior caso so acontece uma vez, porque depois
// Ja seta o pai de cada elemento como o pai raiz
int encontrar(int a){
	if(pai[a] == a)return a; // Se o elemento é pai dele mesmo chegamos a raiz de um grupo disjunto
	else return pai[a] = encontrar(pai[a]); // Senão, checar se o pai de a é raiz
}

// Operação same set
// Retorn true caso pertençam ao mesmo grupo
// e false caso contrário
bool mesmoGrupo(int a, int b){
	return encontrar(a) == encontrar(b);
}

// Operação join
// Uni dois grupos disjuntos
// O com maior tamanho uni com o menor
void unir(int a, int b){
	a = encontrar(a); // encontra a raiz de a
	b = encontrar(b); // encontra a raiz de b
	if(a == b)return; // se ja forem de mesmo grupo, não uni nada
	if(tamanho[a] > tamanho[b])swap(a,b); // se o tamanho de a for maior que o de b, troca os dois
	pai[a] = b; // o pai do menor grupo é a raiz do maior
	tamanho[b] += tamanho[a]; // e o tamanho do grupo maior cresce pelo tamanho do menor
}

int main(){

	cin>>n;

	inicializar();
	
	int unioes;
	cin>>unioes;
	
	while(unioes--){
		int a, b;
		cin>>a>>b;
		unir(a,b);
	}

	for(int i = 0; i < n; i++){
		if(pai[i] == i){
			cout<<"Grupo disjunto "<<i<<" de tamanho "<<tamanho[i]<<endl;
		}
	}

	return 0;
}
