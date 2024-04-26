class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& e) {
        vector<bool>a(e.size(),0); 
        vector<vector<pair<int,int>>>adj(n+1) ; 
        for(auto it : e){
            int u=it[0] , v=it[1] , w=it[2] ; 
            adj[u].push_back({v,w}) ; adj[v].push_back({u,w}) ; 
            
        }
    vector<int> dist(n+1,1e9), parent(n,-1),d(n+1,1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }  
        
        // 0 4 1 2 7 5 1000000000 

     //   for(auto i : dist) cout << i << " " ; 
    //    cout<<"\n"; 
      
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ppq;
    d[n-1] = 0;
    ppq.push({0, n-1});

    while (!ppq.empty()) {
        int u = ppq.top().second;
        ppq.pop();

        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
            //    parent[v] = u;
                ppq.push({d[v], v});
            }
        }
    } 
        
        if(dist[n-1]==1e9) return a;
        
       for(int i=0;i<e.size();i++){
            int u=e[i][0] , v=e[i][1] , w=e[i][2] , flg=0; 
                if ((dist[u]+w+d[v] ==  dist[n-1]) || (dist[v]+w+d[u] == dist[n-1])){
                    a[i]=1;
            }
       }
    return a;
    }
};
//Output: [true,true,true,false,true,true,true,false]
//Output: [true,false,false,true]


