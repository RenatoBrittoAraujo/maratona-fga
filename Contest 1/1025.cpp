#include <bits/stdc++.h>
using namespace std;

int n, q;

int casos = 1;

int main(){

	while(cin>>n>>q, n or q){
	
		vector<int> valores;
		
		int x;

		for(int i = 0; i < n; i++)
			cin>>x, valores.push_back(x);		

		sort(valores.begin(), valores.end());

		cout<<"CASE# "<<casos++<<":\n";

		for(int i = 0; i < q; i++){
			cin>>x;
			auto p = lower_bound(valores.begin(), valores.end(), x);
			if(*p != x)cout<<x<<" not found\n";
			else cout<<x<<" found at "<<(p - valores.begin()) + 1<<endl;

		}

	}

}
