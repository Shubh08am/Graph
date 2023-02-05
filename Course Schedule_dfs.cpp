class Solution {
public: //using dfs cycle detection Algorithm
     bool dfs(int node,vector<int>&vis,vector<int> adj[]){
       //mark visited and pathvisited both by 2 
       vis[node]=2; //using only 1 vis vector for both vis and path vis
        
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>adj[numCourses] ; 
 	    for(auto it :prerequisites){
	        adj[it[1]].push_back(it[0]);
 	    }
        //multiple components
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                //if dfs call returned true any time return true 
                if(dfs(i,vis,adj)==true) {
                    return false; //if cycle exist answer is false
                }
            }
        }
        return true;//if cycle doesn't exist answer is true
    }
}; 
