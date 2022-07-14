#include <bits/stdc++.h>
using namespace std;

bool checkcycle(int node, int parent, vector<int> &vis, vector<int> adj[]){
    
    vis[node]=1;
    for(auto it : adj[node]){
        if(vis[it]==0){
            vis[it]=1;
            if(checkcycle(it, node, vis, adj))return true;
        }else if(it !=parent)return true;
    }return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> vis(n+1,0);
    vector<int> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i])cout<<checkcycle(i, -1, vis, adj)<<"\n";
    }
}
