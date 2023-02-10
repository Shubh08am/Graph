class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //bfs/dfs take node position and distance 
        //if all land or water than -1 
        int n = grid.size();
        int distance=0;
        vector<vector<int>>vis(n,vector<int>(n,0)) ;
        // {{row,col},dist}
        queue<pair<pair<int,int>,int>>q; 
        
        //initally,mark all 1 as visited and push there position in queue 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]==1) { 
                  vis[i][j]=1;
                q.push({{i,j},0});
                }
            }
        } 
        //start bfs concept 
        //if q still empty return -1 as no land or if all land than also -1 
        int currSize = q.size();
       if(currSize==0||currSize==n*n) return -1;

       while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
    //  cout<<"dist "<<dist<<"\n";
        //4 direction traversal
        int dx[]={-1,0,+1,0};
        int dy[]={0,-1,0,+1};
        for(int i=0;i<4;i++){
            int nrow = row + dx[i] ; 
            int ncol = col + dy[i] ; 
    //     cout<<nrow<<" "<<ncol<<"\n";
            //check valid 
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==0){ 
    //            cout<<"inside\n";
                vis[nrow][ncol]=1;
                 distance=max(distance,dist+1); //maximize distance
                //push in queue 
                q.push({{nrow,ncol},dist+1});
            }
        }
       } 
    return distance;
    }
};
