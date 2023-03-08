class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     vector<int>visited(V,0) ; 
     int sum=0;
    //{weight,node} 
     pq.push({0,0});//initally any node can be pushed with 0 as weight 

     while(!pq.empty()){
      auto it = pq.top();
      pq.pop();
      int weight = it.first;
      int node = it.second;
      
      if(visited[node]==1) continue ;
      
      //else check adjacent Nodes if node not visited
      //mark node visited now
      visited[node]=1;
      sum+=weight;
      for(auto it : adj[node]){
        //if not visited 
        int adjNode = it[0] ;
        int edgeWt = it[1] ; 
        //if adjNode not visited
        if(!visited[adjNode]){
                pq.push({edgeWt,adjNode});
        }
    }
}
    return sum;
    }
};
