#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

	int casos;
	cin>>casos;
	
	while(casos--){
		
		priority_queue<ll> azul, verm;
		priority_queue<ll> * ponteiro;

		int pisos;
		cin>>pisos;

		ll valor;

		for(int i = 0; i < pisos; i++){

			cin>>valor;

			if(valor > 0)azul.push(valor);
			else verm.push(-valor);

		}

		if(azul.empty() or verm.empty()){
			cout<<1<<endl;
			continue;
		}

		if(azul.top() > verm.top())
			ponteiro = &azul;
		else 
			ponteiro = &verm;

		int ans = 0;
		ll altura_ultimo = 100000000;

		while(true){
			
			while(!(ponteiro->empty()) and ponteiro->top() >= altura_ultimo)
				ponteiro->pop();

			if(ponteiro->empty())
				break;

			ans++;
			altura_ultimo = ponteiro->top();
			
			if(ponteiro == &verm)
				ponteiro = &azul;
			else ponteiro = &verm;
		}

		cout<<ans<<endl;

	}

}
