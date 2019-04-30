#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

// Algoritmo de euclides extendido

ll euclides_extendido(ll a, ll b, ll &x, ll &y){
    
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = euclides_extendido(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

int main(){

    ll a, b, c;
    ll x, y;
    cin>>a>>b>>c;

    ll maximo_divisor_comum = euclides_extendido(a, b, x, y);

    if(c % maximo_divisor_comum){

        cout<<-1<<endl;
        return 0;
    
    }

    a /= maximo_divisor_comum;
    b /= maximo_divisor_comum;
    c /= maximo_divisor_comum;

    ll resto = ((x % b) * (c % b)) % b;

    if (resto <= 0)
        resto += b;

    if (c <= resto * a){

        cout<<-1<<endl;
        return 0;

    }

    x = resto;
    y = (c - resto * a) / b;

    cout<<x<<' '<<y<<endl;

    return 0;
}