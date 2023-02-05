// User function Template for C++

class Solution{
    public: 
    void topologicalSort(vector<int>adj[] , int indegree [] , string& toposort , int k){
        queue<int>q;
        for(int i=0;i<k;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            toposort+=char(node+'a');
            
            for(auto adjacentNode : adj[node]){
                //remove edge 
                indegree[adjacentNode]--;
                if(indegree[adjacentNode]==0) q.push(adjacentNode);
            }
        }
    }
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<int>adj[k] ; 
        int indegree[k] = {0};
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
                    indegree[v]++;
                    break;//no need to check further
                }
            }
        }
        //now,do topo sort 
        string toposort="" ; 
        topologicalSort(adj,indegree,toposort,k);
    //    cout<<toposort<<"\n";
        return toposort;
    }
};
