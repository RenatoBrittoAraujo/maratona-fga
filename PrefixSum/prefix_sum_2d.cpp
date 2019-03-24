#include <bits/stdc++.h>
using namespace std;

/*
	Imagina que você quer a soma de todos
	os elementos em um retângulo dentro de
	uma array bidimensional em O(1)

	ooooo  a soma de todos os elementos marcados com
	oxxxo  x, por exemplo, um retângulo de (1,1) até (3,3)
	oxxxo 
	oxxxo
	ooooo

*/

const int N = 5 + 10;

int lista[N][N] = { {1,2,3,4,5},
					{1,2,3,4,5},
					{1,2,3,4,5},
					{1,2,3,4,5},
					{1,2,3,4,5} };

int pref[N][N]; // vale lembrar: começa zerada

int main(){

	// construção da soma prefixa bidimensional O(n²)

	for(int i = 1; i < 6; i++){
		for(int j = 1; j < 6; j++){
			
			int soma = lista[i-1][j-1];
			
			soma += pref[i-1][j];
			
			soma += pref[i][j-1];

			soma -= pref[i-1][j-1];

			pref[i][j] = soma;
	
		}
	}

	int x1,y1,x2,y2;

	cout<<"Digite o retângulo que você quer somar\n";

	// assumindo que o input esteja ja tratado,
	// x1 <= x2 e y1 <= y2

	cin>>x1>>y1>>x2>>y2;

	int resposta = pref[x2][y2];

	resposta -= pref[x2][y1 - 1];

	resposta -= pref[x1 - 1][y2];

	resposta += pref[x1 - 1][y1 - 1];
	
	cout<<resposta<<endl;

	return 0;
}
