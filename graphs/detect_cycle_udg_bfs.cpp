#include<bits/stdc++.h>
using namespace std;

bool checkcycle(int node, int n, vector<int> adj[], vector<int> &vis){
    
    queue<pair<int,int>> q;
    
    vis[node] = true;
    q.push({node,-1});
    
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=true;
                q.push({it,node});
            }else if(it!=par){
                return true;
            }
        }
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
        if(!vis[i])cout<<checkcycle(i, n, adj, vis)<<"\n";
    }
    return 0;
}
