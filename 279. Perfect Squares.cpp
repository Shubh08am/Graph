class Solution {
public:
    int numSquares(int n) {
        //bfs 
        //try every path from 1-(i*i<=n) where i = 1,2...sqrt(n) 
        queue<int>q;
        //no,need to push same no. copy in queue to increase iterations and time complexity
        vector<int>vis(10001,0);
        int moves=1;
        //initially,n is pushed 
        q.push(n);

        while(!q.empty()){
            int currSize = q.size();
            
            while(currSize--){
                int node = q.front();
                q.pop(); 
            //    cout<<node<<"\n";
                int i=1;
                while(i*i<=node){ 
                    //not possible 
                    int val = node-i*i;
                    if(val<0){
                        break;
                    } 
                    //found
                    if(val == 0){
                        return moves ; 
                    }
                    else if(!vis[val]){
                        vis[val]=1;
                        q.push(val);
                    }
                    i++;
                }
            }
            moves++;
        }
        return moves;
    }
}; 
