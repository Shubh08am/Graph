class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //simple bfs or dfs works
        int n = rooms.size();
       vector<int>vis(n,0);
       queue<int>q;
       vis[0]=1;//initially 0th room visited
       q.push(0);//0 push as we start bfs from there
       while(!q.empty()){
           int node = q.front() ; 
            q.pop();

            //see keys at that node
            for(auto it : rooms[node]){
               if(!vis[it]) {
                    q.push(it);
                    vis[it]=1;
            }
        } 
    }

    for(int i=0;i<n;i++){
        if(!vis[i]) {
            return false;
            }
    }
     return true ;
    }
};
