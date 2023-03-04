class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int,int>>adj[n+1] ; 
    for(auto it : edges){
        adj[it[0]].push_back({it[1],it[2]});
         adj[it[1]].push_back({it[0],it[2]});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>parent(n+1) , dist(n+1,1e9) ; 
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
    pq.push({0,1}) ; //dist,src 
    dist[1] = 0 ; //src = 1 
    
    while(!pq.empty()){
        int node = pq.top().second ; 
        int dis = pq.top().first ; 
        pq.pop();
        for(auto it : adj[node]){
            int edgeWt = it.second; 
            int adjNode = it.first; 
            
            if(dis+edgeWt < dist[adjNode]){
                dist[adjNode] = dis+edgeWt ; 
                pq.push({dist[adjNode],adjNode});
                //mark in parent where we came from i.e which node to adjNode 
                parent[adjNode] = node ;
            }
        }
    }
    
    //if we didn't reach last node n than no path exist 
    if(dist[n]==1e9) return {-1};
    vector<int>path ; 
    int node = n ; 
     //see at each node where we came from 
    //we are storing path in reverse order 
    while(parent[node]!=node){
         path.push_back(node) ; 
        //update node  
        node = parent[node] ;
    }
    //starting node still left 
    path.push_back(node) ; 
    //reverse the path 
    reverse(path.begin(),path.end()) ; 
    return path ;
    
    }
};
