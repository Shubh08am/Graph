class Solution {
     private:
    int timer=0; //initially,start dfs call and assign tin/low time to every node. We can take any value 0/1 so on

    void dfs(int node , int parent ,vector<int>&vis , vector<int>&tin,vector<int>&low,vector<int>adj[],vector<int>&mark){ 
        vis[node]=1; //mark node initially as visited 
        //assign timer to both tin & low for node 
        tin[node] = low[node] = timer ; 
        timer++; //increment for next node 
        int child = 0 ;
        
        for(auto it : adj[node]){
            if(it==parent) {
        //        cout<<it<<" "<<parent<<"\n";
                continue;
                }
            if(!vis[it]){
                //make a dfs call 
                 dfs(it,node,vis,tin,low,adj,mark);
        //         cout<<it<<" "<<node<<"\n";
                 //assign low[node] as minimum from adjNode 
                 low[node] = min(low[node] , low[it]) ; 
            //i.e we can't reach before node of node && don't apply this logic for starting Node whose parent is -1
                  if(low[it]>=tin[node] && parent!=-1){
                     //articulatePoint exist 
                     mark[node]=1;   
                     }
                child++; 
                /*for starting Node see no. of child if >1 i.e multi-component possible
                
    Why is child++ done inside the if(!vis[it){..} condition -> 
    Even if there are multiple child for the first node, 
    it is possible that all the child might be connected 
    to each other which will not create multiple components, 
    But if they are not connected, so they will be marked 
    as unvisited because if they were connected, 
    through DFS  they would have been visited, 
    therefore in order to find individual child components,
    it is in if condition.
                */
            }
            else if(vis[it]){
                //Same Component no bridge exist but still assign low[node] as minimum from adjNode 
                low[node] = min(low[node] , tin[it]) ; 
                /*take tin[it] & not low[it] as
                it is already visited and we want to go to before node 
                therefore no use to take low[it]
                */
            }

        //if child>1 and parent of starting Node i.e -1 articulatePoint 
        if(child>1 && parent==-1) mark[node]=1;   
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
         //T.C -> O(V+2E) [DFS TRAVERSAL] 
        //S.C -> O(V+2E) [FOR ADJACENCY LIST]  + O(3N) [for vis,tin,low]
        
        //use tin(for insertion time) & Low(for lowest time from adjNode except parent Node)
         vector<int>vis(V,0) , tin(V) , low(V),mark(V) , articulatePoint;

        //multiple components 
        for(int i=0;i<V;i++){
            if(!vis[i]){
                //dfs call :- Initially, -1 is assumed to be parent 
                 dfs(i,-1,vis,tin,low,adj,mark);
            }
        }
         
         for(int i=0;i<V;i++){
            if(mark[i]) articulatePoint.push_back(i);
         }
         
         if(articulatePoint.size()==0) return {-1} ;
         return articulatePoint;
    }
};
 
