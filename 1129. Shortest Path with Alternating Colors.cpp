class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

    vector<int>blue[n];
    vector<int>red[n]; 
    //minimum dist to reach node through blue color,red color
    vector<pair<int,int>>ans(n,{INT_MAX,INT_MAX});
    queue<pair<int,int>>q;
    vector<int>res(n,-1);

    int distance=0;
    for(auto it:redEdges){
        red[it[0]].push_back(it[1]);
    }
     
    for(auto it:blueEdges){
        blue[it[0]].push_back(it[1]);
    }
        
    ans[0]={0,0};
    
    q.push({0,-1});//for red
    q.push({0,1});//for blue
    
    while(!q.empty()) { 
        int size=q.size();
        
       for(int i=0;i<size;i++){   
            auto it=q.front();
            q.pop();
            
          int node=it.first;
          int edge=it.second; 

        // if edge is blue traverse adj list of blue edges   
           if(edge==1) {
               for(auto curr:blue[node]) { 
                   int currentDist = distance+1 ; 
                    int previousDist = ans[curr].second;
                   if(previousDist>currentDist){
                       ans[curr].second=currentDist; 
                       q.push({curr,-1});
                   }
               }
           }
           // if edge is red traverse adj list of red edge
           else{
                for(auto curr:red[node]) { 
                    int currentDist = distance+1 ; 
                    int previousDist = ans[curr].first;
                   if(previousDist>currentDist) {
                       ans[curr].first=currentDist ;
                       q.push({curr,1});
                   }
               }
           }
       }
        distance++;
    }

    for(int i=0;i<n;i++) {
        int mn=min(ans[i].first,ans[i].second); 
        // possible to reach
        if(mn!=INT_MAX){
            res[i]=mn;
        }
    }
    return res;
    }
};
