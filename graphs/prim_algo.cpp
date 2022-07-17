#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    int parent[n];
    int key[n];
    bool mstSet[n];
    
    
    for(int i=0;i<n;i++){
        parent[i] = -1;
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    
    
    for(int count = 0; count < n-1; count++){
        int mini = INT_MAX;
        int u;
        
        for(int i=0;i<n;i++){
            if(mstSet[i]==false && key[i]<mini){
                mini = key[i];
                u = i;
            }
        }
    
    mstSet[u] = true;
    
    for(auto it : adj[u]){
        int v = it.first;
        int wt = it.second;
        
        if(mstSet[v]==false && key[v]>wt){
            parent[v] = u;
            key[v] = wt;
        }
    }
    }
    
    for(int i=0; i<n; i++){
        cout<<parent[i]<<"-"<<i<<"-"<<key[i]<<"\n";
    }
    
    
    return 0;
}
