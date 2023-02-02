class Solution
{
	public: 
	void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&s){
	    vis[node]=1;
	    for(auto adjacentNode : adj[node]){
	        if(!vis[adjacentNode]){
	          vis[adjacentNode]=1;
	            dfs(adjacentNode,vis,adj,s);
	        }
 	    }
	      s.push(node);
 //dfs call done than only push as node-> {a,b,c,... } so first in stack(from top to bottom)
 //node,a,b,c.... and when popped out 
 //in topo sort --> node,a,b,c..... 
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    vector<int>topological ; 
	    vector<int>vis(V,0);
	    stack<int>s;
	    //multiple components 
	    for(int i=0;i<V;i++){
	        if(!vis[i]) {
	            dfs(i,vis,adj,s);
	        }
	    }
	    //take out linear ordering from stack 
	    while(!s.empty()){
	        topological.push_back(s.top());
	        s.pop();
	    }
	  //  for(auto it : topological) {
	  //      cout<<it<<" ";
	  //  }
	    return topological;
	}
};
