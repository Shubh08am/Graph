class Solution {
  public:
  vector<int> dfs(int node, vector<int> adj[] ,vector<int>&vis , vector<int>&ans) {
      vis[node]=1;
      ans.push_back(node);
       
      for(auto it : adj[node]){
          if(!vis[it]){
              vis[it]=1;
              dfs(it,adj,vis,ans);
          }
      }
      return ans;
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<int>vis(V,0);
        dfs(0,adj,vis,ans);
        return ans;
    }
};
