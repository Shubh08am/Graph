 class Solution {
  public:
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int,int>>adj[N] ; 
       for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int weight = edges[i][2]; 
        //    cout<<u<<" "<<v<<" "<<weight<<"\n";
             adj[u].push_back({v,weight});
        }
      queue<pair<int,int>>q; 
           q.push({0,0});
        //distance thing 
        vector<long> dist(N,INT_MAX);
        int sourceNode = 0 ; 
        dist[sourceNode]=0;
        
        while(!q.empty()){
            int node = q.front().first;
            q.pop() ; 
            
            for(auto it : adj[node]){
                int v= it.first  , weight = it.second; 
                //distance to reach v is dist till node + weight 
              long  distanceOfv= dist[node] + weight  ; //so,that no overflow happens
              long prev_distanceOfv = dist[v];
                if(distanceOfv<prev_distanceOfv){
                    //update to shortest one 
                    dist[v] = distanceOfv;
                    q.push({v,distanceOfv});
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
