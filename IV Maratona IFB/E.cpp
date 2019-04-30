#include <bits/stdc++.h>

using namespace std;


int main(){
    
    double g, d;
    double total;

    cin>> g >> d >> total;

    double resp = ((total * 1000.0)/(double)g) * 
                   ((100.0 / (double)(100 - d)));

    printf("%.8lf\n", (resp)); 

}