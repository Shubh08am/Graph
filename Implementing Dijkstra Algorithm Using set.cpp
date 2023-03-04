class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         vector<int>distance(V,1e9);
         //make min heap 
          set<pair<int,int>>s;
         //initially,src with dist = 0 is pushed 
         s.insert({0,S});
         //src distance from src is 0 
         distance[S]=0;
         
         while(!s.empty()){
             auto it = *(s.begin());
             int node = it.second ; 
             int dist = it.first ; 
             s.erase(it) ; 
             
             for(auto it : adj[node]){ 
                 int edgeWt = it[1] ; 
                 int adjNode = it[0] ; 
                 
                 if(dist+edgeWt < distance[adjNode]){
                     //remove the older path as of no use as we found shorter path 
                     //only, if we visited that same node earlier 
                     if(distance[adjNode] != 1e9) {
                         //remove older node 
                         s.erase({distance[adjNode],adjNode}); 
                     }
                     //update the adjNode and inseret in set 
                     distance[adjNode] = dist+edgeWt;
                     s.insert({distance[adjNode] ,adjNode});
                 }
             }
         }
         return distance;
    }
};
