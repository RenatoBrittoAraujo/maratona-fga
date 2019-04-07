#include <bits/stdc++.h>
using namespace std;

bool v[10000];

int main(){

	int n, r, x;

	while(cin>>n>>r, !cin.eof()){

		memset(v, 0, sizeof v);

		for(int i = 0; i < r; i++)
			cin>>x,
			v[x - 1] = 1;


		bool todosVivos = 1;

		for(int i = 0; i < n; i++)
			if(!v[i])todosVivos = 0, cout<<i + 1<<' ';

		if(todosVivos)cout<<'*';
		cout<<endl;

	}

}
