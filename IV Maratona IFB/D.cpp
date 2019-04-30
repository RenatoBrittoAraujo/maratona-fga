#include <bits/stdc++.h>
using namespace std;

string prox(string atual){

    string nova;

    char ultimo = atual[0];

    int indice = 1;

    while(true){

        int cnt = 1;

        while(indice < atual.size() and atual[indice] == ultimo)
            indice++, cnt++;

        nova += to_string(cnt) + ultimo;
        
        if(indice == atual.size())
            break;
        
        ultimo = atual[indice];

        indice++;
    }

    return nova;

}

int main(){

    string atual = "1";

    int n;
    cin>>n;

    for(int i = 1; i < n; i++){

        atual = prox(atual);

    }

    cout<<atual<<endl;

}