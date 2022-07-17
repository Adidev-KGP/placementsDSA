#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    int key[n];
    int par[n];
    bool mstSet[n];
    
    for(int i=0;i<n;i++){
        key[i] = INT_MAX;
        par[i] = -1;
        mstSet[i] = false;
    }
    
    key[0] = 0;
    
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    
    pq.push({0,0});
    
    
    for(int count = 0; count<n-1; count++){
        int u = pq.top().second;
        pq.pop();
        
        mstSet[u] = true;
        
        for(auto it : adj[u]){
            int v = it.first;
            int weight = it.second;
            if(mstSet[v] == false && key[v] > weight){
                key[v] = weight;
                par[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    for(int i=0; i<n; i++){
        cout<<par[i]<<"-"<<i<<"-"<<key[i]<<"\n";
    }
    
    return 0;
}
