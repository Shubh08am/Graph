// User function Template for C++

class Solution {
  public: 
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid, vector<pair<int,int>>&vp,int baseRow,int baseCol){
        vis[row][col]=1;
        //insert in vp first  shape after removing base row & base col
        vp.push_back({row-baseRow,col-baseCol});
        //all 4 direction 
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,-1,0,+1};
        int n = grid.size() , m = grid[0].size();
        
        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
             
            //check valid 
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,vis,grid,vp,baseRow,baseCol);
            }
        }
    }
    
     void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>> &grid, 
    vector<pair<int, int>> &vp, int baseRow, int baseCol){
        int n = grid.size() , m = grid[0].size();
        queue<pair<int, int>> q;
        vis[row][col] = 1;
        q.push({row, col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
             vp.push_back({row-baseRow,col-baseCol});
             q.pop();
            
           int delRow[]={-1,0,+1,0};
           int delCol[]={0,-1,0,+1}; 
           for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
             
            //check valid 
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
 
        vector<pair<int,int>>vp;
        set<vector<pair<int,int>>>s;
        int n = grid.size() , m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //it should not be visited 
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>vp;//stores shape 
                    int baseRow=i;
                    int baseCol=j;
                    //dfs(i,j,vis,grid,vp,baseRow,baseCol);
                    bfs(i,j,vis,grid,vp,baseRow,baseCol);
                    //store unique shape i.e islands in set 
                    s.insert(vp);
                }
            }
        }
        return s.size();
    }
};
