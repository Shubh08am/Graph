class Solution {
public:
    void dfs(int startingNode ,vector<int>&visited,vector<int>adjacencyList[]){
         //mark starting node as visited 
         visited[startingNode]=1;
         //now,go inside adjacency list for each node and traverse 
         for(auto it : adjacencyList[startingNode]){
             //if that node is not visited than do dfs traversal
             if(!visited[it]){
                 dfs(it,visited,adjacencyList);
             }
         }
    }
    void bfs(int startingNode ,vector<int>&visited,vector<int>adjacencyList[]){
        queue<int>q;
        //initially push startingNode in queue 
        q.push(startingNode); 
        //also,mark it as visited
        visited[startingNode]=1;

        while(!q.empty()){
            int node  = q.front();
            q.pop();
            visited[node]=1; 
            //now,go and traverse level wise for node 
            for(auto it : adjacencyList[node]){
                if(!visited[it]){
                q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //create a adjacency list 
        int n = isConnected.size();
        vector<int>adjacencyList[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //no self path and path exist 
                if(i!=j and isConnected[i][j]==1){
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }
        int Provinces = 0 ; 
        //create a visited vector 
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            //if not visited than do bfs or dfs traversal 
            if(!visited[i]){
               // dfs(i,visited,adjacencyList);
                bfs(i,visited,adjacencyList);
                Provinces++;
            }
        }
        return Provinces;
    }
};
