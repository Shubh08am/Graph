
class Solution{
    private:
    void dfs(int node,vector<int>&vis,vector<vector<int>>& adj,stack<int>&st){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node); //store in stack
    }
    void dfs3(int node,vector<int>&vis,vector<vector<int>>& adjRev){
        vis[node]=1;
        for(auto it : adjRev[node]){
            if(!vis[it]){
                dfs3(it,vis,adjRev);
            }
        }
     }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj){
        vector<int>vis(V,0) ; 
        stack<int>st;//stores nodes according to finishing time
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        
        //Now,reverse all the edges 
        vector<vector<int>>adjRev(V);
        for(int i=0;i<V;i++){
            for(auto&it : adj[i]){ 
                //i -> it now after reversing it ->i
                adjRev[it].push_back(i) ; 
            }
        }
        
    //apply,dfs on stack now 
    int scc=0;
    //mark vis as 0 again 
     for(int i=0;i<V;i++) vis[i]=0;
     
     while(!st.empty()){
         int node=st.top();
         st.pop();
         if(!vis[node]){
             dfs3(node,vis,adjRev);
             scc++;
         }
     }
     return scc;
    }
};
