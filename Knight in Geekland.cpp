//User function Template for C++

class Solution{
public:
    int knightInGeekland(int x,int y,vector<vector<int>> &arr){
          int n=arr.size(),m=arr[0].size();
        //BFS to calculate total points in each step without using magical power
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{x,y},0});
        vis[x][y]=1;
        vector<int>ans(1e3+1,0);
        int drow[]={-1,-2,-2,-1,1,2,2,1};
        int dcol[]={-2,-1,1,2,-2,-1,1,2};
        while(!q.empty()){
            int row=q.front().first.first; 
            int col=q.front().first.second;
            int tx=q.front().second;
            q.pop();
            ans[tx]+=arr[row][col];
            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    q.push({{nrow,ncol},tx+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        //check total points in each step using magical power
        int res=0,mxpnt=0,sx;
        for(int i=0;i<=(1e3);i++){
            sx=i;
            while(sx<=(1e3) && ans[sx]!=0){
                sx+=ans[sx];
                if(sx<=(1e3)) ans[i]+=ans[sx];
            }
            if(ans[i]>mxpnt){
                res=i;
                mxpnt=ans[i];
            }
        }
        return res;
    }
};
