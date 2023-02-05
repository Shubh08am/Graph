class Solution{
    public: 
    void topologicalSortDFS(int node , vector<int>adj[],int vis[],string &toposort ,int k){
           vis[node]=1;
            for(auto adjacentNode : adj[node]){ 
                if(!vis[adjacentNode]){
               topologicalSortDFS(adjacentNode,adj,vis,toposort,k)   ; 
              }
        }
      toposort+=char(node+'a');  
    }
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<int>adj[k] ;
        int vis[k]={0};
         //compare two strings and check when not equal character and make a directed graph and do topo sort 
        for(int i=0;i<N-1;i++){
            string s1 = dict[i]; 
            string s2 = dict[i+1];
            int length = min(s1.size(),s2.size()) ; //iterate till min of both length
            for(int i=0;i<length;i++){
                if(s1[i]!=s2[i]){
                    //s1[i] -> s2[i] 
                    int u = s1[i]-'a' ; 
                    int v = s2[i]-'a';
                    adj[u].push_back(v);
                     break;//no need to check further
                }
            }
        }
        //now,do topo sort 
        string toposort="" ; 
        for(int i=0;i<k;i++){
            if(!vis[i]){
        topologicalSortDFS(i,adj,vis,toposort,k);
            }
        }
      reverse(toposort.begin(),toposort.end());//as we used stack originally that stores in reverse order
      //cout<<toposort<<"\n"; 
        return toposort;
    }
};
