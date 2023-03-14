// User function Template for C++
class DSU{
public:
vector<int>parent , rank , size ; 
//constructor created 
DSU(int n){
    //declare size for vector 
    parent.resize(n+1) ;  //n+1 as it covers both 0 & 1 based indexing
    rank.resize(n+1,0) ;  //initially, every node rank is marked as 0
    size.resize(n+1,1) ;  //initially, every node size is marked as 1

    //initially,every node is a parent of itself 
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
}

//find Ultimate Parent  
int findUltimateParent(int node){
       if(node==parent[node]) return node ; 
       //doing,path compression by assigning value to parent[node] and making T.C  as O(4*alpha) --> O(1)
       return parent[node] = findUltimateParent(parent[node]) ;
}

//Disjoint Set -> [1] finding Union By Rank 
void UnionByRank(int u , int v){
    int ulp_u = findUltimateParent(u) ; //UltimateParent of u 
    int ulp_v = findUltimateParent(v) ; //UltimateParent of v

    //if belonging to same components 
    if(ulp_u == ulp_v) return;

    //if not belonging to same components 
    if(rank[ulp_u]<rank[ulp_v]){
        //smaller guy gets connected to larger guy and no change in rank of ulp_u or ulp_v 
        //update parent of smaller guy
        parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_u]>rank[ulp_v]){
        //smaller guy gets connected to larger guy and no change in rank of ulp_u or ulp_v 
        //update parent of smaller guy
        parent[ulp_v]=ulp_u;
    }
    else if(rank[ulp_u]==rank[ulp_v]){
        //Anyone can get connected to other node and change in rank of node to which connected
        //update parent of node which gets connected
        parent[ulp_v]=ulp_u; //connecting ulp_v to ulp_u 
        rank[ulp_u]++;
    }
}

//Disjoint Set -> [2] finding Union By Size 
void UnionBySize(int u , int v){
    int ulp_u = findUltimateParent(u) ; //UltimateParent of u 
    int ulp_v = findUltimateParent(v) ; //UltimateParent of v

    //if belonging to same components 
    if(ulp_u == ulp_v) return;

    //if not belonging to same components 
    if(size[ulp_u]<size[ulp_v]){
        //smaller guy gets connected to larger guy and change in size to which connected
        //update parent of smaller guy
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else if(size[ulp_u]>size[ulp_v]){
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
    else if(size[ulp_u]==size[ulp_v]){
        //Anyone can get connected to other node and change in size of node to which connected
        //update parent of node which gets connected
        parent[ulp_v]=ulp_u; //connecting ulp_v to ulp_u 
        size[ulp_u]+=size[ulp_v];
    }
}
};


class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
         int n = details.size();
        DSU ds(n);
        unordered_map<string,int>mailId ; 

        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                   string mail = details[i][j] ; 
                if(mailId.find(mail) != mailId.end()){
                      //already present make connection dynamically using dsu
                  //    ds.UnionBySize(mailId[mail],i) ;
                        ds.UnionByRank(mailId[mail],i) ;

                }
                else{
                    mailId[mail] = i ;
                }
            }
        }

    //Now,store all mail-id in ans 
    vector<string>ans[n] ; 
    for(auto it : mailId){
        string mail = it.first ; 
        int pos = it.second ; 
        int parentOfPos  = ds.findUltimateParent(pos); 
        //now,store mail also in parentOfPos as they belong to same user 
        ans[parentOfPos].push_back(mail);
    }

    vector<vector<string>>res ;
    for(int i=0;i<n;i++){ 
        if(ans[i].size()==0) continue; //as we don't want only user name without any mail id
        //sort all mailId
        sort(ans[i].begin() , ans[i].end()) ; 
        //also at start all user name should be there 
        vector<string>user ; 
        user.push_back(details[i][0]) ; 
        //now,push all mail id of user 
        for(auto it : ans[i]){
            user.push_back(it) ; 
        }
      //add in res 
      res.push_back(user);
    }
    reverse(res.begin() , res.end());
    return res;
    }
};
