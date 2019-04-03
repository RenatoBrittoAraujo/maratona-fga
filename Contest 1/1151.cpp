#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;

	int a = 0, b = 1;

	for(int i = 0; i < n; i++){

		if(i & 1)
			printf("%d", b),
			a = a + b;
		else
			printf("%d", a),
			b = a + b;

		if(i != n - 1)printf(" ");

	}

	printf("\n");

}
