class Solution {
  public: 
   bool dfs(int node,vector<int>&vis,vector<int>&pathvisited,vector<int> adj[]){
       //mark visited and pathvisited both 
       vis[node]=1; 
       pathvisited[node]=1;
       
       for(auto adjacentNode : adj[node]){
           //if node is not visited 
           if(!vis[adjacentNode]){
               vis[node]=1; //mark visited
               pathvisited[node]=1;
               if(dfs(adjacentNode,vis,pathvisited,adj)==true) return true;
           }
           //if node has been visited and it is also in the same path i.e cycle exist
           else if(vis[adjacentNode]  && pathvisited[adjacentNode] ){
               return true;
           }
       }
       pathvisited[node]=0;//unmark the node path as not visited in same path
       return false ;
   }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // undirected logic fails 
        vector<int>vis(V,0),pathvisited(V,0);
        
        //multiple components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                //if dfs call returned true any time return true 
                if(dfs(i,vis,pathvisited,adj)==true) {
                    return true;
                }
            }
        }
        return false;
    }
};
