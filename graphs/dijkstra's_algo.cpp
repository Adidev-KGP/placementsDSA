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
    int src;
    cin>>src;
    
    vector<int> distTo(n+1,INT_MAX);
    distTo[src] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,src});
    
    while(!pq.empty()){
        int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for( it = adj[prev].begin() ; it != adj[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}
    
    for(auto it : distTo)cout<<it<<" ";
    return 0;
}
