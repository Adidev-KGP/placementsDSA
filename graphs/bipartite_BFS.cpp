#include<bits/stdc++.h>
using namespace std;

bool bipartitebfs(int src, vector<int> adj[], vector<int> &color){

    color[src] = 1;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int node= q.front();
        q.pop();
        
        for(auto it : adj[node]){
            if(color[it]==-1){
                color[it] = 1-color[node];
                q.push(it);
            }else if(color[it]==color[node])return false;
        }
    }return true;
}

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> color(n+1,-1);
    vector<int> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
           if(!bipartitebfs(i, adj, color)){
               cout<<0<<"\n";
               break;
           }else cout<<bipartitebfs(i, adj, color);
        }
        
    }
    return 0;
}
