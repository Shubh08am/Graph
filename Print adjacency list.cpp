class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>>v;vector<int>vv;
        for(int i=0;i<V;i++){
            vv.push_back(i);
            for(auto it : adj[i]){
                vv.push_back(it);
            }
            v.push_back(vv);
            vv.clear();
        }
        return v;
    }
};
