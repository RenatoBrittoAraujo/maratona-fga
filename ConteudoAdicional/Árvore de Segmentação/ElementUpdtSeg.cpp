#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int n;

int a[N];
int st[N];

void build(int p = 1, int l = 0, int r = n){
	if(r - l < 2){
		st[p] = a[l];
		return;
	}	
	
	int m = (l+r)/2;
	
	build(p * 2, l, m);
	build(p * 2 + 1, m, r);
	
	st[p] = st[p*2] + st[p*2+1];
}

int sum(int e,int d,int p = 1,int l = 0,int r = n){
	if(e >= r or l >= d)return 0;
	if(e <= l and r <= d)return st[p];

	int m = (l+r)/2;
	
	return sum(e,d,p*2,l,m)+sum(e,d,p*2+1,m,r);	
}

void modify(int v,int x,int p = 1,int l = 0,int r = n){
	st[p] += v - a[x];
	if(r - l < 2){
		a[x] = v;
		return;
	}
	
	int m = (l+r)/2;
	
	if(x < p)modify(v, x, 2*p, l, m);
	else modify(v, x, 2*p + 1, m ,r);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int l,r;
	
	build();
	
	cin>>l>>r;
	modify(l,r);
	cout<<sum(0,n)<<endl;

	return 0;
}
