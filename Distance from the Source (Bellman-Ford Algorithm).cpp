// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
         vector<int>dist(V,1e8);
         dist[S]=0;
         
         //(V-1) times Relaxation 
         for(int i=0;i<V-1;i++){
             for(auto it : edges){
                 int u = it[0] , v = it[1] , wt = it[2] ; 
                 //condition && if node reachable i.e dist[u]!=1e8 
                 if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                     dist[v]=dist[u]+wt;
                 }
             }
         }
        //for negative cycle :- Do Nth iteration if distance gets updated negative cycle present 
       for(auto it : edges){
                 int u = it[0] , v = it[1] , wt = it[2] ; 
                 //condition && if node reachable i.e dist[u]!=1e8 
                 if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                     //gets updated
                     //dist[v]=dist[u]+wt;
                     return {-1};
                 }
             }  
    return dist;
    }
};
