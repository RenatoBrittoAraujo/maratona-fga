#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

vector<int> G[N];
bool visited[N];

void dfs(int u) {
    visited[u] = 1;

    for(auto v: G[u])
        if (!visited[v])
            dfs(v);
}

int main()
{
    int n,m;
    while(cin>>n>>m,bool(n+m)){

        int x,y,z;
       
	    for(int i=0;i<m;i++){
       
	        cin>>x>>y>>z;
            G[x-1].push_back(y-1);
            if(z==2)G[y-1].push_back(x-1);
       
	    }
       
	    bool val=true;
       
	    for(int i = 0; i < n; i++){
       
	        memset(visited,0,sizeof visited);
            dfs(i);
			
            for(int j = 0; j < n; j++)
				
				if(visited[j] != 1){
				
					val=false;
					break;
				
				}

            if(!val)break;
       
	    }
       
	    if(val)cout<<1;
        else cout<<0;

		cout<<endl;
       
	    for(int i = 0;i < n; i++)
			G[i].clear();
    }
    return 0;
}
