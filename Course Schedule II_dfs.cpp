class Solution {
public: 
     bool dfs(int node,vector<int>&vis,vector<int> adj[] , stack<int>&s){
       //mark visited and pathvisited both by 2 
       vis[node]=2; //using only 1 vis vector for both vis and path vis
        
       for(auto adjacentNode : adj[node]){
           //if node is not visited 
           if(!vis[adjacentNode]){
               vis[node]=2; //mark visited and pathvisited both  
                if(dfs(adjacentNode,vis,adj,s)==true) return true;
           }
           //if node has been visited and it is also in the same path i.e cycle exist (shown by 2)
           else if(vis[adjacentNode]==2){
               return true;
           }
       }
       vis[node]=1;//unmark the node path as not visited in same path i.e only visited now shown with 1 
       s.push(node);//dfs call over than push
       return false ;
   }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0),ans;
        vector<int>adj[numCourses] ; 
        stack<int>s;
 	    for(auto it :prerequisites){
	        adj[it[1]].push_back(it[0]);
 	    }
        //multiple components
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                //if dfs call returned true any time return true 
                if(dfs(i,vis,adj,s)==true) {
                    return {}; //if cycle exist answer is empty vector
                }
            }
        }
        while(!s.empty()) {
            ans.push_back(s.top()) ; 
            s.pop() ;
        }
        return ans; 
    }
};
