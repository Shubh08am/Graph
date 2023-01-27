class Solution {
  public:
    vector<int> bfs(int V ,vector<int> adj[],vector<int>&vis,vector<int>&ans){
        vis[0]=1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it); 
                vis[it]=1;
            }
            }
            q.pop();
        }
        return ans;
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        vector<int>ans;
        bfs(V,adj,vis,ans);
        return ans;
    }
};
