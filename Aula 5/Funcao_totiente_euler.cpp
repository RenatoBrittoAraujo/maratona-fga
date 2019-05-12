#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Função Totiente de Euler, complexidade O(sqrt(n))
ll phi(ll n)
{
	ll ans = n;
	for(ll i = 2LL; i * i <= n; i++)
	{
		if(n % i == 0LL)
		{
			while(n % i == 0LL)
				n /= i;
			ans -= ans / i;
		}
	}

	if(n > 1)
		ans -= ans / n;

	return ans;
}

int main()
{
	
	ll n;

	cout<<"Numero de naturais coprimos a N: "<<phi(n)<<endl;	

	return 0;
}
