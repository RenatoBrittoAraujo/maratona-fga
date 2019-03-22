
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int a[N];
int lazy[4*N];
int s[4*N];
int n;

void print_lazy(int p){
	for(int i=0;i<p;i++)cout<<lazy[i]<<' ';cout<<endl;
}

void print_seg(int p){
	for(int i=0;i<p;i++)cout<<s[i]<<' ';cout<<endl;
}

void build(int p = 1,int l = 0,int r = n){
	
	if(r - l < 2){
		s[p] = a[l];
		return;
	}
	int m = (l + r)/2;
	build(p * 2, l, m);
	build(p * 2 + 1, m, r);
	s[p] = s[p * 2] + s[p * 2 + 1];
}

void update(int id,int l,int r,int x){
	lazy[id] += x;	// deixa update guardado para seus filhos
 	s[id] += (r - l)* x; // e atualiza seu prórpio valor equivalente ao tamanho
}			     // da sub-árvore vezes a mudança x 
 

void shift(int id,int l,int r){
	int mid = (l+r)/2; 
	update(id*2,l,mid,lazy[id]); // atualizar filhos
	update(id*2+1,mid,r,lazy[id]);
	lazy[id] = 0;	// sem mais atualizações
}

void increase(int x,int y,int v,int id = 1,int l = 0,int r = n){
	if(x>=r or l>=y)return; // sem intersecção
	if(x<=l and r<=y){	// [l,r) está contido em [x,y)
		update(id,l,r,v); // atualizar pai e deixar lazy update para os filhos
		return;
	}
	shift(id,l,r);	// caso não estar contido, atulizar filhos
	int mid = (l+r)/2;
	increase(x,y,v,id*2,l,mid); // realizar mesma operação
	increase(x,y,v,id*2,mid,r); // nos filhos
	s[id] = s[id*2] + s[id*2+1]; // e atualizar seu valor para a mudança dos filhos
}

int sum(int x,int y,int id = 1,int l = 0,int r = n){
	if(x>=r or l>=y)return 0;
	if(x<=l and r<=y)return s[id];
	shift(id,l,r); // atualiza seus filhos antes
	int mid = (l+r)/2; // depois calcula soma
	return sum(x,y,id*2,l,mid) + sum(x,y,id*2+1,mid,r);
	
}

int main(){
	cin>>n;
	
	for(int i=0;i<n;i++)cin>>a[i];
	
	build();
		
	int l,r,op,x;
		
	while(1){
		cout<<"LAZY = ";print_lazy(20);
		cout<<"SEG  = ";print_seg(20);
		cout<<"OPERATION -> ";cin>>op;
		if(op==1){
			cout<<"INTERVAL INCREASE\n";
			cin>>l>>r>>x;
			increase(l,r,x);
		}else{
			cout<<"INTERVAL SUM\n";
			cin>>l>>r;
			cout<<sum(l,r)<<endl;
		}
	}
	
}
