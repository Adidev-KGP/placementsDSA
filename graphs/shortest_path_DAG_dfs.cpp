#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, stack<int> &st, vector<int> &vis, vector<pair<int,int>> adj[]){
    
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it.first]){
            topoSort(it.first, st, vis, adj);
        }
    }st.push(node);
}

vector<int> shortestpath(int src, int n, vector<pair<int,int>> adj[]){
    
    vector<int> vis(n+1,0);
    stack<int> st;
    
    for(int i=0;i<n;i++){
        if(!vis[i])topoSort(i, st, vis, adj);
    }
    
    vector<int> dist(n+1,INT_MAX);
    dist[src]=0;
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        if(dist[node]!=INT_MAX){
            for(auto it : adj[node]){
                if(dist[node]+it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    return dist;
}

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    
    for(auto it : shortestpath(0, n, adj)) cout<<it<<" ";
    
    return 0;
}
