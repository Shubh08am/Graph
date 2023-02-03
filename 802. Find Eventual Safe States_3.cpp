class Solution {
public: //Using, Topological Sort
// T.C -> O(V+E) + O(VLOGV) 
// S.C. -> O(V+V)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)  {
    int V= graph.size();
    vector<int>adjacenyListReverse[V];
    vector<int>indegree(V,0);
   
    for(int i=0;i<V;i++){ 
        //reverse the link 
        for(auto adjacentNode : graph[i]){
          //before:- i->adjacentNode
          //after:- adjacentNode->i 
          adjacenyListReverse[adjacentNode].push_back(i);
          indegree[i]++;
        }
    }
    queue<int>q;
    vector<int>SafeNodes;
    //initially,all terminal nodes whose indegree is 0 is pushed in queue 
    for(int i=0;i<V;i++){ 
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
       SafeNodes.push_back(node);
     //check in adjacenyListReverse as link updated
        for(auto adjacentNode : adjacenyListReverse[node]){
        //remove the edge and decrease the indegree 
        indegree[adjacentNode]--;

        if(indegree[adjacentNode]==0) {
            q.push(adjacentNode);
        }
        }
    }
   //at,last sort it 
   sort(SafeNodes.begin(),SafeNodes.end());
   return SafeNodes;
    }
};
