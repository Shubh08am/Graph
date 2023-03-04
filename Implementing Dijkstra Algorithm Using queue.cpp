class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         vector<int>distance(V,1e9);
         //make min heap 
          queue<pair<int,int>>pq;
         //initially,src with dist = 0 is pushed 
         pq.push({0,S});
         //src distance from src is 0 
         distance[S]=0;
         
         while(!pq.empty()){
             int node = pq.front().second ; 
             int dist = pq.front().first ; 
             pq.pop() ; 
             
             for(auto it : adj[node]){ 
                 int edgeWt = it[1] ; 
                 int adjNode = it[0] ; 
                 
                 if(dist+edgeWt < distance[adjNode]){
                     distance[adjNode] = dist+edgeWt;
                     pq.push({distance[adjNode] ,adjNode});
                 }
             }
         }
         return distance;
    }
};
