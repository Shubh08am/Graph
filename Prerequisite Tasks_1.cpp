class Solution {
public:
    bool topologicalSort(int N ,vector<int>adj[] ,vector<int>&indegree){
        queue<int>q;
        int topologcalSort=0;
        
        for(int i=0;i<N;i++){
            if(indegree[i]==0){ 
                q.push(i);
                  }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topologcalSort++;
            //go and see in adjacenecy list neighbour 
            for(auto it : adj[node]){
               //remove the edge and decrease the indegree 
                indegree[it]--;
              //  if indegree[it] becomes 0 push in queue 
               if(indegree[it]==0){ q.push(it);
                }
            }
        } 
        return topologcalSort==N ;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here 
	    vector<int>adj[N] ; 
	    vector<int>indegree(N,0);
	    for(auto it :prerequisites){
	        adj[it.second].push_back(it.first);
	        indegree[it.first]++;
	    }
	   return topologicalSort(N,adj,indegree) ; 
	}
};
