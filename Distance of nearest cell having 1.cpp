class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    //bfs approach
	    
	    int n = grid.size()  , m = grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>distance(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	            q.push({{i,j},0});
	            vis[i][j]=1;
	                
	            }
	        } 
	    }
	    
	    vector<int>delRow={-1,0,+1,0};
	    vector<int>delCol={0,-1,0,+1};
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int step = q.front().second;
	        q.pop();
	        //mark its distance 
	        distance[row][col]=step;
	        //visit 4 neighbour 
	        
	        for(int i=0;i<4;i++){
	            int nrow = row + delRow[i] ; 
	            int ncol = col + delCol[i] ; 
	            
	            //check valid 
	     if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==0){
	         vis[nrow][ncol]=1;
	         q.push({{nrow,ncol},step+1});
	     }
	        }
	    }
	    return distance;
	}
};
