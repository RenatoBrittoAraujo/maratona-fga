#include <bits/stdc++.h>
using namespace std;

set<string> num;
string s;

int main(){

	int n;
	while(cin>>n, !cin.eof()){

		while(n--){
			
			cin>>s;
			num.insert(s);

		}

		bool val = 0;
		int ans = 0;

		for(auto numero: num){

			if(!val){
				
				s = numero;
				val = 1;
				continue;

			}

			for(int i = 0; i < s.size() and numero[i] == s[i]; i++)
				ans++;

			s = numero;
	
		}

		cout<<ans<<endl;
		num.clear();

	}

}
