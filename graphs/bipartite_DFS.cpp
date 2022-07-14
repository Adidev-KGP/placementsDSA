#include<bits/stdc++.h>
using namespace std;

bool bipartitedfs(int src, vector<int> adj[], vector<int> &color){
    
    if(color[src]==-1)color[src]=1;
    
    for(auto it : adj[src]){
        if(color[it]==-1){
            color[it]=1-color[src];
            if(!bipartitedfs(it, adj, color))return false;
        }else if(color[it]==color[src])return false;
    }return true;
}

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> color(n+1,-1);
    
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(bipartitedfs(i, adj, color))cout<<1<<"\n";
            else {
                cout<<0<<"\n";
                break;
            }
        }
    }
    return 0;
}
