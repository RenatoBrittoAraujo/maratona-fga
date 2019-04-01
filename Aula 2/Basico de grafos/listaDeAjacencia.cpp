#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

vector<int> grafo[N];

int main(){

	int v, e;
	cin>>v>>e;

	for(int i = 0; i < e; i++){
	
		int a,b;
		cin>>a>>b;

		grafo[a].push_back(b); // se for unicamente direcionado
		//grafo[b].push_back(a); // se for não-direcionado	

	}

	for(int i = 0; i < v; i++){

			cout<<"Vetice "<<i<<" se conceta com: ";
			
		for(auto v: grafo[i]){

			cout<<v<<' ';

		}

		cout<<endl;

	}

}
