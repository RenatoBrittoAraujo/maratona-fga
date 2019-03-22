
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5; // 1e5 == 1 * 10 elevado a quinta, 2e5 == 2 * 10 elevado a quinta

int a[N]; // array de valores

int st[4*N]; // array da arvore de segmentos

int n;

void build(int p = 1,int l = 0,int r = n){
	
	if(r - l < 2){
		st[p] = a[l];	//se tamanho do intervo for 1
		return;
	}
	
	int m = (l + r)/2; // meio entre l,r

	build(p * 2, l, m); //constroi esquerda
	build(p * 2 + 1, m, r); //constroi direita

	st[p] = st[p * 2] + st[p * 2 + 1]; //atualizar valor da posição
}

int sum(int e,int d,int p = 1,int l = 0,int r = n){
	
	if(d <= l or r <= e)return 0; // intersecção vazia

	if(l >= e and r <= d)return st[p]; // [l,r) está contido em [e,d)

	int m = (l+r)/2;

	return sum(e, d, p * 2, l, m) + sum(e, d, p * 2 + 1, m, r); // soma dos filhos do nodo
	
}

int main(){
	cin>>n; // tamanho da nossa array
	
	for(int i=0;i<n;i++)cin>>a[i]; // leitura da array
	
	build(); // contrução da árvore O(n*log(n))
	
	for(int i=0;i<20;i++)cout<<st[i]<<' ';cout<<endl;
		
	int l,r;
		
	while(1){
		cin>>l>>r; // intervalo [l,r) vai de l, l+1, l+2,..., r-3, r-2, r-1 

		cout<<sum(l,r)<<endl;	// soma dos elementos da array de [l,r}
		
	}	
	
}
