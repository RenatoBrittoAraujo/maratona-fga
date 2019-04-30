#include <bits/stdc++.h>

using namespace std;

string s;

int c[30];

int main(){

    cin >> s;

    // Soma do numero de ocorrencias de cada caractere

    for(int i = 0; i < (int)s.size(); ++i)
        c[s[i]-'A']++;

    int f = 0;

    // Para ser palindromo, pode possuir, no máximo, um caractere
    // repetido um numero ímpar de vezes

    for(int i = 0; i < 26; ++i)
        if(c[i] & 1)
            f++;

    if(f > 1)
        cout<<"Não"<<endl;
    else
        cout<<"Sim"<<endl;

    return 0;

}