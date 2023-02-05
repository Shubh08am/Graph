class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int> adj[]){
       //mark visited and pathvisited both by 2 
       vis[node]=2; 
        
       for(auto adjacentNode : adj[node]){
           //if node is not visited 
           if(!vis[adjacentNode]){
               vis[node]=2; //mark visited and pathvisited both  
                if(dfs(adjacentNode,vis,adj)==true) return true;
           }
           //if node has been visited and it is also in the same path i.e cycle exist (shown by 2)
           else if(vis[adjacentNode]==2){
               return true;
           }
       }
       vis[node]=1;//unmark the node path as not visited in same path i.e only visited now shown with 1
       return false ;
   }
	bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
	    // Code here 
	   vector<int>vis(V,0);
        vector<int>adj[V] ; 
 	    for(auto it :prerequisites){
	        adj[it.second].push_back(it.first);
 	    }
        //multiple components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                //if dfs call returned true any time return true 
                if(dfs(i,vis,adj)==true) {
                    return false;
                }
            }
        }
        return true;
	}
};
