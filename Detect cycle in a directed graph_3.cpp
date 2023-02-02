class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
          queue<int>q;
	    vector<int>indegree(V,0);
 	    vector<int>Topological;
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    //push in queue node whose indegree is 0 , atleast one node will be there if it is valid DAG
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) {
 	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        Topological.push_back(node);
	        for(auto adjacetNode:adj[node]){
 	     //remove the edge between node->adjacentNode i.e indegree of adjacentNode is decreased
	     indegree[adjacetNode]--;
	     //if indegree of adjacetNode becomes 0 push in queue
	     if(indegree[adjacetNode]==0) q.push(adjacetNode);
	     }
	  } 
 	  return Topological.size()==V?0:1; //that means if in topological every node comes that mean no cycle 
    }
};
