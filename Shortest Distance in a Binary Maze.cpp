 class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        //No,need to use priority queue as distance already stored in increasing order
        //Therefore we can use queue.
        
        //{distance,{row,col}}
         queue<pair<int,pair<int,int>>>q;
         int n = grid.size() , m = grid[0].size() ; 
         vector<vector<int>>dist(n,vector<int>(m,1e9)) ; 
         // mark source distance as 0
         dist[source.first][source.second]=0;
         q.push({0,{source.first,source.second}});
         
         //4 direction traversal 
         int dx[]={-1,0,+1,0};
         int dy[]={0,-1,0,+1};
         
         while(!q.empty()){
             auto it = q.front();
             q.pop();
             int dis = it.first ; 
             int row = it.second.first , col = it.second.second; 
             // or return here 
           // if(row==destination.first && col==destination.second) return dis;
             //traverse all 4 direction 
             for(int i=0;i<4;i++){
                 int newRow = row + dx[i] ; 
                 int newCol = col + dy[i] ; 
      
      
                 //check valid && 1 at grid and dijkstra condition 
         if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1 
            && dis + 1 < dist[newRow][newCol]){
                //reach destination 
      if(newRow==destination.first && newCol==destination.second) return dis+1;
                dist[newRow][newCol] = dis + 1 ;
                q.push({dis + 1 ,{newRow,newCol}});
            }
             }
         }
         //edge case if at starting only source equals destination 
         if(source.first==destination.first && source.second==destination.second) return 0;
         return -1; //not able to reach destination
    }
};
