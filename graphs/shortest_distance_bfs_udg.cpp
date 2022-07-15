#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int src, int n, vector<int> adj[]){
    
    vector<int> dist(n+1,INT_MAX);
    dist[0]=0;
    
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto it : adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }return dist;
    
}

int main(){
    
    int n,m;
    cin>>n>>m;
    
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(auto it : bfs(0, n, adj))cout<<it<<" ";
    
    return 0;
}
