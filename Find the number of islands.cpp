class Solution {
  public:
  void bfs(int row, int col , vector<vector<char>>& grid,vector<vector<int>>& vis, int n , int m ){
      vis[row][col]=1;
      queue<pair<int,int>>q;
      q.push({row,col});
      
      while(!q.empty()){
          int row = q.front().first ; 
          int col = q.front().second ; 
          q.pop();
          //all neighbours 
          for(int delrow = -1 ; delrow<=1 ; delrow++){
             for(int delcol = -1 ; delcol<=1 ; delcol++){
               int nrow=row+delrow;
               int ncol=col+delcol;
               
               //check valid or not 
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                   vis[nrow][ncol]=1;
                   q.push({nrow,ncol});
               }
           } 
          }
      }
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size() , m = grid[0].size() , cnt=0; 
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                //if not vis and 1 
                if(!vis[row][col] and grid[row][col]=='1'){
                    //do bfs or dfs 
                    cnt++;
                    bfs(row,col,grid,vis,n,m);
                }
            }
        }
        return cnt;
    }
};
