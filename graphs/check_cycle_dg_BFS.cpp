#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<int> adj[]){
    queue<int> q;
    vector<int> indegree(n+1,0);
    
    for(int i=1;i<=n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }
    
    vector<int> topo;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }return topo;
}


int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    vector<int> topo = topoSort(n, adj);
    if(topo.size()==n)cout<<1<<"\n";  // 1 means could produce a toposort therefore its not a cyclic graph
    else cout<<0<<"\n";  // 0 means couldn't produce a toposort therefore its a cyclic graph
    
    return 0;
}
