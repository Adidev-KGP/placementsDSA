#include<bits/stdc++.h>
using namespace std;

void topoSortDfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &toposort){
    
    vis[node]=1;
    
    for(auto it : adj[node]){
        if(!vis[it]){
            topoSortDfs(it, adj, vis, toposort);
        }
    }toposort.push(node);
}

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> vis(n+1,0);
    stack<int> toposort;
    
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            topoSortDfs(i, adj, vis, toposort);
        }
    }
    
    while(!toposort.empty()){
        cout<<toposort.top();
        toposort.pop();
    }
    
    return 0;
}
