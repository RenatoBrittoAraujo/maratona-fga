#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

using ll = long long;

int n, m;

// Fenwick tree, ou BIT, 2d
// Leia mais aqui: https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/

int arvore[N][N];

void atualiza(int x, int y, int val){
    
    while(y <= m) {

        int id = x;

        while(id <= n) {

            arvore[id][y] += val;

            id += id & (-id); // Dígito menos significativo

        }

        y += y & (-y);

    }

}

int query(int x, int y){

    int retorno = 0;

    while(y){

        int id = x;

        while(id){

            retorno += arvore[id][y];
            id -= id & (-id);

        }

        y -= y & (-y);
    }

    return retorno;

}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            int x;
            scanf("%d", &x);
            atualiza(i, j, x);

        }
    }

    int q, x1, y1, x2, y2, op, v;

    scanf("%d", &q);

    while(q--){
        
        scanf("%d", &op);

        if(op == 0){

            scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
            printf("%d\n", query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1));
        
        }else{

            scanf("%d %d %d", &y1, &x1, &v);
            atualiza(x1, y1, v);

        }

    }

}