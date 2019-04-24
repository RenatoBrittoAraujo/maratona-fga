
#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define loop(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define len(a) (int)(a).size()
#define allv(a) (a).begin(),(a).end()
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fLL;
const double err = 1e-9;
const int mod = 1e9+7;
const int N = 1e5+10;

void multiplica(ll A[2][2], ll B[2][2]){

	ll x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	ll y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	ll w = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	ll z = A[1][0] * B[0][1] + A[1][1] * B[1][1];

	A[0][0] = x % mod;
	A[1][0] = w % mod;
	A[0][1] = y % mod;
	A[1][1] = z % mod;

}

ll elevado(ll n){

	ll B[2][2] = {{1,1},{1,0}};

	ll F[2][2] = {{1,0},{0,1}};

	while(n > 0){

		if(n & 1)
			multiplica(F, B);

		multiplica(B, B);

		n >>= 1;
	}
	
	return F[0][0];

}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	
	ll n;
	cin>>n;
	cout<<elevado(n)<<endl;

	return 0;
}
