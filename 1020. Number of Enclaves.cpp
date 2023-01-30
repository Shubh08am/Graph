class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //surrounded by X problem concept 
        //both bfs & dfs works 
        //doing by bfs 
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        //initially find one on all 4 boundary 
        for(int i=0;i<m;i++){
            //first row 
            if(grid[0][i]==1 and !vis[0][i]){
             //   cout<<"0 "<<i<<" \n";
                vis[0][i]=1;
                q.push({0,i});
            }
              //last row 
            if(grid[n-1][i]==1 and !vis[n-1][i]){
                 //   cout<<n-1<<i<<" \n";
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }
        for(int i=0;i<n;i++){
            //first column 
            if(grid[i][0]==1 and !vis[i][0]){
                //   cout<<i<<"0 "<<" \n";
                vis[i][0]=1;
                q.push({i,0});
            }
              //last column 
            if(grid[i][m-1]==1 and !vis[i][m-1]){
                 //   cout<<i<<m-1<<" \n";
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        
        vector<int>delRow = {-1,0,+1,0};
        vector<int>delCol = {0,-1,0,+1};
        while(!q.empty()){
           int row = q.front().first;
           int col = q.front().second;
           q.pop();
           //check all 4 neighbour
           for(int i=0;i<4;i++){
               int nrow = row+delRow[i] ; 
               int ncol = col+delCol[i];

               //check valid
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                   vis[nrow][ncol]=1;
                   q.push({nrow,ncol});
               }
           }
        }
int Enclaves=0;
 //at,last check in grid if 1 is there and corresponding to that if in vis 0 than its our answer as we can't go out from there
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         if(grid[i][j]==1 && vis[i][j]==0){
             Enclaves++;
         }
     }
 }  
 return Enclaves;
    }
};
