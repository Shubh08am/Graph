class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxTime=0,freshOrange=0;
           //{{row,col},time}
        queue<pair<pair<int,int>,int>>q;
        //find rotten orange and push in queue as doing bfs traversal 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                 if(grid[i][j]==1) freshOrange++;
            }
        }
    //traverse all 4 neighbours
      vector<int>delRow={-1,0,+1,0};
      vector<int>delCol={0,-1,0,+1};


    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();
        maxTime=max(maxTime,time);

        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];

            //check valid 
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                //mark visited 
                vis[nrow][ncol]=2;
                q.push({{nrow,ncol},time+1});
                freshOrange--;//freshOrange that are pushed in queue
            }
        }
    }

     if(freshOrange!=0) return -1; //as freshOrange still left 
         return maxTime;
    }
};
