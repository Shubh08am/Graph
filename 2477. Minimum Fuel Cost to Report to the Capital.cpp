class Solution {
public:
    long long fuelCost=0;
    int dfs(int src,int parent,vector<vector<int>>& adj,int seats) {
    int people = 1 ; 
    for(auto adjNode : adj[src]){ 
        //no call when at 0 
        if(adjNode!=parent){ 
        people+=dfs(adjNode,src,adj,seats);
        }
    }
    //if not reached 0 see for fuelCost 
    if(src!=0){ 
    fuelCost+=ceil(people/(seats*1.0));
    } 
 //   cout<<fuelCost<<" ";
        return people;//we keep returning no of people we have at car to next node
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
       int n = roads.size()+1 ;
       vector<vector<int>>adj(n);

        for(auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
         //we go deep to the level of each node therefore apply dfs and while returning we get fuelCost 
        dfs(0,-1,adj,seats);
        return fuelCost;
    }
};
