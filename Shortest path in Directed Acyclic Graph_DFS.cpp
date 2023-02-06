 class Solution {
  public:
   void toposort(int node ,vector<pair<int,int>>adj[],int vis[],stack<int>&s){
       vis[node]=1;
       for(auto it : adj[node]){
           int v = it.first;
           if(!vis[v]){
               toposort(v,adj,vis,s);
           }
       }
       s.push(node);//dfs call over
   }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int,int>>adj[N] ; 
       for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int weight = edges[i][2]; 
        //    cout<<u<<" "<<v<<" "<<weight<<"\n";
             adj[u].push_back({v,weight});
        }
        //find topo sort 
        int vis[N]={0}; stack<int>s; 
          for(int i=0;i<N;i++){
            if(!vis[i]){
                toposort(i,adj,vis,s);
            }
        }
        
        //distance thing 
        vector<long> dist(N,INT_MAX);
        int sourceNode = 0 ; 
        dist[sourceNode]=0;
        
        while(!s.empty()){
            int node = s.top();
            s.pop() ; 
            
            for(auto it : adj[node]){
                int v= it.first  , weight = it.second; 
                //distance to reach v is dist till node + weight 
              long  distanceOfv= dist[node] + weight  ; 
              long prev_distanceOfv = dist[v];
                if(distanceOfv<prev_distanceOfv){
                    //update to shortest one 
                    dist[v] = distanceOfv;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX) dist[i] = -1 ; //not reachable
        } 
        vector<int>ans(N);
          for(int i=0;i<N;i++){
             ans[i] = dist[i]    ; //not reachable
        }
    return ans;
    }
};
