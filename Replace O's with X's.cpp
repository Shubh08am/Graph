// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board) { 
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        // first and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                vis[0][j] = 1;
                q.push({0,j});
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                vis[n-1][j] = 1;
                q.push({n-1,j});
            }
        }
        // first and last coloum
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                vis[i][0] = 1;
                q.push({i,0});
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                vis[i][m-1] = 1;
                q.push({i,m-1});
            }
        }
        vector<int>delRow={-1,0,+1,0} ; 
        vector<int>delCol={0,+1,0,-1} ; 
        while(q.size()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        return board;
    }
};
