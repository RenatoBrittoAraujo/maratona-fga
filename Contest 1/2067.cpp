#include <bits/stdc++.h>
using namespace std;

const int N = 210;

int quad[N][N];
int pref[N][N];

int main(){

	int l,c;
	cin>>l>>c;

	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			cin>>quad[i][j];
		}
	}

	for(int i = 1; i <= l; i++){
		for(int j = 1; j <= c; j++){
			pref[i][j] += !quad[i-1][j-1];
			pref[i][j] += pref[i-1][j];
			pref[i][j] += pref[i][j-1];
			pref[i][j] -= pref[i-1][j-1];
		}
	}


	/*
	for(int i = 0; i <= l; i++){
		for(int j = 0; j <= c; j++){
			cout<<pref[i][j]<<' ';
		}
		cout<<endl;
	}
	*/

	int q;
	cin>>q;

	int s;

	while(q--){
		
		cin>>s;
		bool val = 0;

		for(int i = s; !val and i <= l; i++){
			for(int j = s; !val and j <= c; j++){
			
				int tz = 0;

				tz += pref[i][j];
				tz -= pref[i - s][j];
				tz -= pref[i][j - s];
				tz += pref[i - s][j - s];

				if(tz == 0)
					val = 1;
			}
		}

		cout<<(val ? "yes" : "no")<<endl;

	}

}
