class Solution {
  public:
   void dfs(int i,vector<vector<int>>& adj,vector<int>&  tmp,vector<int>& vis){
        vis[i]=1;
        tmp.push_back(i);
        
        for(auto& ele: adj[i]) {
                if(!vis[ele])
                    dfs(ele,adj,tmp,vis);
            }
    }
  
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
       int n=V;
       vector<int> vis(n+1,0);
       int ct=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]) {   
                    vector<int> tmp;
                    dfs(i,adj,tmp,vis);
                    int tp=0;
                    for(auto& ele: tmp){
                        tp+=adj[ele].size();
                    }
                    int f=tmp.size();
                    if(tp/2==f*(f-1)/2)
                        ct++;
                }
        }
        return ct;
    }
};
