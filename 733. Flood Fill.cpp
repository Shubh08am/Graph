class Solution {
public:
    void bfs(int row, int col , vector<vector<int>>& image,
   vector<vector<int>>& ans, int n , int m ,vector<int>delrow,vector<int>delcol , 
   int newcolor , int initialColor)  {
      ans[row][col]=newcolor;
      queue<pair<int,int>>q;
      q.push({row,col});
      
      while(!q.empty()){
          int row = q.front().first ; 
          int col = q.front().second ; 
          q.pop();
          //all neighbours 
          for(int i =0 ; i<4 ; i++){

               int nrow=row+delrow[i];
               int ncol=col+delcol[i];
               
               //check valid or not 
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialColor && ans[nrow][ncol]!=newcolor){
                   ans[nrow][ncol]=newcolor;
                   q.push({nrow,ncol});
           } 
           
          }
      }      
  }
   void dfs(int row, int col , vector<vector<int>>& image,
   vector<vector<int>>& ans, int n , int m ,vector<int>delrow,vector<int>delcol , 
   int newcolor , int initialColor)  {
      ans[row][col]=newcolor;
          for(int i =0 ; i<4 ; i++){
               int nrow=row+delrow[i];
               int ncol=col+delcol[i];
               
               //check valid or not 
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialColor && ans[nrow][ncol]!=newcolor){
                   ans[nrow][ncol]=newcolor;
             dfs(nrow,ncol,image,ans,n,m,delrow,delcol,newcolor,initialColor);
           } 
      }      
  }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int n = image.size() , m = image[0].size() ; 
        vector<vector<int>>ans=image;
        int initialColor = image[sr][sc];
        vector<int>delrow = {-1,0,+1,0};
        vector<int>delcol = {0,-1,0,+1};
       // bfs(sr,sc,image,ans,n,m,delrow,delcol,newColor,initialColor);
       dfs(sr,sc,image,ans,n,m,delrow,delcol,newColor,initialColor);

        return ans;
    }
};
