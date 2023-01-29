class Solution {
  public: 
  //bfs 
  bool detectCycle(int source,vector<int>&vis,vector<int> adj[]){
      vis[source]=1;
      // {node,parent}
      queue<pair<int,int>>q;
      q.push({source,-1});
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          for(auto adjacentNode : adj[node]){
              if(!vis[adjacentNode]){
              //node is parent & adjacentNode is child 
              vis[adjacentNode]=1;
              q.push({adjacentNode,node});
          }
          //cycle exist 
          else if(vis[adjacentNode] && parent!=adjacentNode){
              return true;
          }
      }
      }
      return false;
  }
  
bool dfs(int source,int parent,vector<int>&vis,vector<int> adj[]){
 vis[source]=1;
 for(auto adjacentNode : adj[source]){
              if(!vis[adjacentNode]){
              //node is parent & adjacentNode is child 
              vis[adjacentNode]=1;
              //if true returned 
              if(dfs(adjacentNode,source,vis,adj)==true) return true;
           }
          //cycle exist 
          else if(vis[adjacentNode] && parent!=adjacentNode){
              return true;
          }
      }
      return false;


}
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       vector<int>vis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]){
               //using bfs
            //   if(detectCycle(i,vis,adj)==true){
            //       return true;
            //   }
            //using dfs
            if(dfs(i,-1,vis,adj)==true) return true;
           }
       }
       return false;
    }
};
