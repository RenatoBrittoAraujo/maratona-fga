#include <bits/stdc++.h>
#define pb push_back

using namespace std;

using ll = long long int;

vector<ll> fib;

// Ordem de construção da string é F(n - 2) + F(n - 1)

bool algoritmo_valido(ll n, int p){

	// Caso base

	// Retorna 0 se p == 1
	// E 1 se p == 2

	if(p < 3)
		return bool(p - 1);

	// Pega o tamanho da primeira substring que compoe string do algoritmo atual

	ll v = fib[p - 2];

	// Se o tamanho for menor ou igual ao da anterior, volta à string que correponde a primeira parte da atual

	if(n <= v)
		return algoritmo_valido(n, p - 2);

	// Caso contrário, retorna à posição da string que coresponde a segunda parte da atual
	// Na posição válida dela (no caso, n - v), v sendo o tamanho da string atual

	else 
		return algoritmo_valido(n - v, p - 1);

}

// Praticamente a mesma lógica, só muda os detalhes da recusão pois a ordem é F(n - 1) + F(n - 2)

bool algoritmo_invalido(ll n, int p){

	if(p < 3)
		return bool(p - 1);

	ll v = fib[p - 1];

	if(n <= v)
		return algoritmo_invalido(n, p - 1);
	else
		return algoritmo_invalido(n - v, p - 2);

}

int main(){

	int n;
	cin>>n;

	fib.pb(0LL);
	fib.pb(1LL);

	int sz = 1;

	// Calcula todos os fibonnacci's até 2 x 10¹⁸
	// que são 91 valores, pouca coisa

	while(fib.back() < 2e18){

		fib.pb(fib[sz] + fib[sz - 1]);
		sz++;	

	}

	bool val = true;

	ll x;

	// 0 significa 'A'
	// 1 significa 'B'

	// O tamanho da string n = fib(n)

	for(int i = 0; i < n; i++){
		
		cin>>x;

		// Acha o indice do primeiro número de fibonacci maior ou igual a x na array fib

		int p = lower_bound(fib.begin(), fib.end(), x) - fib.begin();

		// Realiza recursão para achar o dígito apontado pelo algoritmo correto e incorreto
		// Se em algum momento forem discrepantes, significa que deu WA

		if(val and algoritmo_valido(x, p) != algoritmo_invalido(x, p))
			val = false;

	}

	cout<<(val ? "AC" : "WA")<<endl;

	return 0;
}
