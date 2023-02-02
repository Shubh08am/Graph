class Solution {
public:
    bool dfs(int node, vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathvis){
        vis[node]=1;
        pathvis[node]=1;
        
        //if cycle exist not safe node
        for(auto adjacentNode:graph[node]){
         if(!vis[adjacentNode]){
             //if we found cycle any point of time return true 
             if(dfs(adjacentNode,graph,vis,pathvis)==true){
                 return true;//not safe node  
             }
         }
             //if adjacentNode is visited and in the same path cycle exist
             else if(vis[adjacentNode] && pathvis[adjacentNode]){
                  return true;//not safe node 
             }
        }
        //after checking when we come out that means no cycle exist and it is safenode 
        pathvis[node]=0;//as nodde is not a part of cycle remove it 
        return false;//no cycle
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>SafeNodes;
        //multiple components 
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis);
            }
        }
        //atlast all safe nodes are marked as 0 in pathvis 
        for(int i=0;i<V;i++){
            if(pathvis[i]==0) SafeNodes.push_back(i);
        }
        return SafeNodes;
    }
};
