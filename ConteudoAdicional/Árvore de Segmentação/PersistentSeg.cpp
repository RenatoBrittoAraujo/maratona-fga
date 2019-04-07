
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n;
int L[N*4];
int R[N*4];
int s[N*4];
int a[N];
int root[4*N];
int cnt = 1,ir = 0;

void build(int id=ir,int l=0,int r=n){
	//cout<<"CALL BUILD "<<id<<' '<<l<<' '<<r<<endl;
	if(r-l<2){
		s[id] = a[l];
		return;
	}
	int m = (l+r)/2;
	L[id] = cnt++;
	R[id] = cnt++;
	
	build(L[id],l,m);
	build(R[id],m,r);
	s[id] = s[L[id]] + s[R[id]]; 
}

int upd(int p,int v,int id,int l = 0,int r = n){
	int i = cnt++;
	if(r-l<2){
		a[p] += v;
		s[i] = a[p];
		return i;
	}
	int mid = (l+r)/2;
	L[i] = L[id], R[i] = R[id];
	if(p<mid) L[i] = upd(p,v,L[i],l,mid);
	else R[i] = upd(p,v,R[i],mid,r);
	s[i] = s[L[i]] + s[R[i]];
	return i;
}	

int sum(int x,int y,int id,int l = 0,int r = n){
	if(x>=r or l>=y)return 0;
	if(x<=l and r<=y)return s[id];
	int mid = (l+r)/2;	
	return sum(x,y,L[id],l,mid) + sum(x,y,R[id],mid,r);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	
	int a,b,c,op;
	
	bool fq = 0;
	
	build();
	root[0] = 0;
			

	while(1){	
		cout<<"SEG = ";for(int i=0;i<20;i++)cout<<s[i]<<' ';cout<<endl;
		cout<<"L   = ";for(int i=0;i<20;i++)cout<<L[i]<<' ';cout<<endl;
		cout<<"R   = ";for(int i=0;i<20;i++)cout<<R[i]<<' ';cout<<endl;
		cout<<"OPERATION -> ";cin>>op;
		if(op == 1){
			cout<<"ADD QUERY\n";cin>>a>>b;
			ir++;
			root[ir] = upd(a,b,root[ir-1]);
			cout<<"ROOT["<<ir<<"] = "<<root[ir]<<endl;
		}else{
			cout<<"SUM QUERY\n";cin>>a>>b>>c;
			cout<<"INTERVAL ["<<a<<','<<b<<") on version "<<c<<" = "<<sum(a,b,root[c])<<endl;
		}
	}	
	
	
	return 0;
}
