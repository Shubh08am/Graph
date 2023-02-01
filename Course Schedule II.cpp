class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int>indegree(numCourses,0);
        vector<int>adjList[numCourses];// adjacenecy list
        queue<int>q;
        for(auto it : prerequisites){
            adjList[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        vector<int>topologcalSort,ans;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){ 
                q.push(i);
                  }
        } 
        //push neighbour in queue if indegree[val] becomes 0 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topologcalSort.push_back(node);
            //go and see in adjacenecy list neighbour 
            for(auto it : adjList[node]){
                //remove the edge and decrease the indegree 
                indegree[it]--;
              //  if indegree[it] becomes 0 push in queue 
               if(indegree[it]==0) q.push(it);
            
            }
        } 
     //   if(topologcalSort.size()!=numCourses) return {};
     //   return topologcalSort;
       return ((topologcalSort.size()==numCourses)?topologcalSort:ans)  ;
    }
};
