 class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {

         int step=0;
         queue<pair<int,int>>q;
         vector<int>vis(100000,0);
         vis[start]=1;
         //{step,value}
        q.push({0,start});
               
         while(!q.empty()){
             int step = q.front().first ; 
             int val = q.front().second ; 
             q.pop() ; 
              if(val==end) return step;
              for(int i=0;i<arr.size();i++){ 
                  int x = (arr[i]*val)%100000 ;
                if(!vis[x]){
                 q.push({step+1,x});
                 vis[x]=1;
             } 
         }
         }
         return -1;
    }
};
