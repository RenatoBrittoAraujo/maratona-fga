#include <bits/stdc++.h>

using namespace std;

bool isprime[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);

	// Define todos os valores da array como 1
	memset(isprime, 1, sizeof isprime);

	// Vale lembrar: 1 NÃO É primo
	isprime[1] = false;

	for(int i = 2; i  < N; i++){
	
		if(isprime[i]){ // Se valor esta marcado como primo então nenhum multiplo dele é
		
			for(int j = i + i; j < N; j+=i){

				isprime[j] = false; // Marco multiplo como não primo 

			}

		}

	}

	while(1){

		int v;
		cin>>v;
		cout<<(isprime[v]?"É primo":"Não é primo")<<endl;

	}

	return 0;
}
