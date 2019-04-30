#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], pref[N];

int main(){

    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++)
        cin>>a[i];

    // Atribui 1 se o par de valores for estritamente crescente
    //        -1 se o par for estritamente decrescente
    //         0 caso sejam iguais

    for(int i = 1; i < n; i++){

        if(a[i] < a[i - 1])
            pref[i] = -1;

        else if(a[i] > a[i - 1])
            pref[i] = 1;
     
	    else 
			pref[i] = 0;

	}

    // Realiza a soma prexixa, ou seja, cada indice na rray b representa a soma
    // de todos os indices anteriores

    for(int i = 1; i < n; i++)
        pref[i] += pref[i - 1];

    int q;
    cin>>q;

    while(q--){

        int l,r;
        cin>>l>>r;

        // Se o intervalo na soma prefixa tiver a soma de valores
        // igual a r - l, significa que é completamente crescente

        if(pref[r] - pref[l] == (r - l))
            cout<<"crescente\n";
        
        // Se o valor do intervalo na soma prefixa for igual
        // -(r - l), significa que é completamente descrescente

        else if(pref[r] - pref[l] == -(r - l))
            cout<<"decrescente\n";
        
        // Caso não se encaixe nessas categorias, então não é nem
        // crescente nem decrescente.

        else
            cout<<"nenhum\n";
    }

}
