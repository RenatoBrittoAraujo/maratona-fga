#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;

bool primes[N];

int main(){

    int t;
    cin>>t;

    memset(primes, 1, sizeof primes);

    // Crivo de erastótenes calculando todos os primos até 10 elevado a 7
    
    for(int i = 2; i < N; i++){

        if(primes[i]){

            for(int j = i + i; j < N; j+=i){

                primes[j] = 0;
                    
            }
	
	    }

    }

    primes[1] = 0;

    while(t--){

        int n;
        cin>>n;

        bool val = 1;

        // Enquanto o numero for maior que zero e for primo, remova o ultimo digito dele

        while(n > 0 and primes[n])
            n/=10;
        
        if(n > 0)
            cout<<"N\n";

        else cout<<"S\n";


    }

}
