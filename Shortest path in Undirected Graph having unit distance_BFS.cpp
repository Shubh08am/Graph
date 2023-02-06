 class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here 
        //create a adjacency list 
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            //undirected 
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<long>dist(N,INT_MAX);
        dist[src]=0;
        
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop() ; 
            for(auto adjacentNode : adj[node]){
                //distance of node froms src
                int distanceTillNode = dist[node] ; 
    //distance from node to adjacentNode is 1 thus distance of  adjacentNode from src is distance of node + 1 
                long long int distanceTilladjacentNode = dist[node] + 1 ;//to prevent overflow
                int previousdistanceofadjacentNode = dist[adjacentNode];
                
                //update the smaller one
                if(previousdistanceofadjacentNode>distanceTilladjacentNode){
                    dist[adjacentNode] = distanceTilladjacentNode ; 
                    //push in queue adjacentNode
                    q.push(adjacentNode);
                }
            }
        }
        vector<int>ans(N);
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                ans[i]=-1;
            }
            else ans[i] = dist[i];
        }
        return ans;
    }
};
