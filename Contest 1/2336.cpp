#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

ll fexp(ll base, ll exp, ll m = mod){

	ll ans = 1;

	while(exp > 0){

		if(exp & 1)ans = ans * base % m;

		exp >>= 1;

		base = base * base % m;

	}

	return ans;

}

int main(){

	string s;
	while(cin>>s, !cin.eof()){

		ll ans = 0;

		for(int i = 0; i < (int)s.size(); i++){
		
			ans += fexp(26LL, (int)s.size() - 1 - i) * ll(s[i] - 'A');

			ans %= mod;

		}

		cout<<ans<<endl;
	
	}
	
}
