class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {

         queue<pair<int,int>>q;
          vector<int>dis(100000,1e9);
          dis[start]=0;
         //{step,value}
         q.push({start,0});
               
         while(!q.empty()){
             int step = q.front().second ; 
             int val = q.front().first ; 
             q.pop() ; 
             
              for(int i=0;i<arr.size();i++){ 
                  int x = (arr[i]*val)%100000 ;
                  //dijkstra algo
                if(dis[x] > step+1){ 
                    dis[x]=step+1;
                    if(x==end) return step+1;
                 q.push({x,step+1});
             } 
         }
         }
         return -1;
    }
};
