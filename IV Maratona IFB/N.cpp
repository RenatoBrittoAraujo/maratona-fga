#include <bits/stdc++.h>

using namespace std;

using ll  =long long;
using est = pair<pair<ll,ll> , int>;
#define f first
#define s second

// Parametros de desempate, maior baloes e menor tempo
// Comparador leva isso em conta

bool desempate(est a, est b){

    return a.f.f == b.f.f ? a.f.s < b.f.s : a.f.f > b.f.f;

}

int main(){

    int n;
    cin>>n;

    ll m;
    cin>>m;

    // est: pair de (pair de (numero de balões, tempo final), indice)

    vector<est> competidores;

    for(ll i = 0; i < n; i++){

        ll a,b;
        cin>>a>>b;

        competidores.push_back({{a,b},i + 1});

    }

    // Indice dos estraga festa: 0
    // Tempo de solução das questões é m * 300

    competidores.push_back({{m, m * 300LL}, 0LL});

    // Organizou as equipes por ordem de melhor para pior de acordo
    // com os critérios de desempate

    sort(competidores.begin(), competidores.end(), desempate);

    int i = 1;

    vector<est> vencedores;

    // Por definição, o primeiro já é vencedor 

    vencedores.push_back(competidores[0]);

    // Enquanto os próximos colocados estão empatados com o primeiro
    // colocado, adicionar na lista de vencedores

    while(  i < (int)competidores.size() and 
            competidores[i - 1].f.s == competidores[i].f.s and
            competidores[i-1].f.f == competidores[i].f.f)
                vencedores.push_back(competidores[i]), i++;

    for(int i = 0; i < (int)vencedores.size(); i++)

        // Se os estraga-festa estão entre os vencedores, então estragaram a festa

        if(vencedores[i].s == 0){

            cout<<"S\n";
            return 0;

        }
    
    cout<<"N\n";

    return 0;

}