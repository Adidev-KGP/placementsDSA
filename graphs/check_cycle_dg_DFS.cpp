#include<bits/stdc++.h>
using namespace std;

bool checkcycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis){
    vis[node]=1;
    dfsvis[node]=1;
    
    for(auto it : adj[node]){
        if(!vis[it]){
            if(checkcycle(it, adj, vis, dfsvis))return true;
        }else if(dfsvis[it])return true;
    }
    dfsvis[node]=0;
    return false;
}

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> vis(n+1,0);
    vector<int> dfsvis(n+1,0);
    
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(checkcycle(i, adj, vis, dfsvis))cout<<1<<"\n";
            else {
                cout<<0<<"\n";
                break;
        }
        
    }
}
    return 0;
}
