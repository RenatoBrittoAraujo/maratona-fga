#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

using ll = long long;

int n;

double v[N];

int main(){

    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);

    // Para balançear usando o trocando o mínimo possível
    // de valores de pote para pote, basta igualar à mediana (não média)

    double mediana;

    if(n & 1)
        mediana = v[n/2];
    else
        mediana = (v[n/2] + v[n/2 - 1]) / 2.0;

    double ans = 0;

    // Para cada valor, somar o módulo da sua diferença com a mediana

    for(int i = 0; i < n; ++i)
        ans += fabs(v[i] - mediana);

    cout<<fixed<<setprecision(6)<<ans<<endl;
    

}