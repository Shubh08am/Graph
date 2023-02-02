class Solution {
public:
    bool bfscheck(int start,vector<int>&colour,vector<int>adj[]){
        queue<int>q;
        q.push(start);
        //colour that node 
        //assuming two colour 0&1 and starting with 0 
        colour[start]=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
        for(auto adjacentNode:adj[node]){
           
           //colour adjacentNode with opposite colour of node if not yet coloured 
           if(colour[adjacentNode]==-1){
           colour[adjacentNode]=(!colour[node]) ; //i.e opposite of node colour 
           //push in queue 
           q.push(adjacentNode);
           }
           //else when both neighbours have same colour not a bipartite graph 
           else if(colour[adjacentNode]==colour[node]) {
               return false;
           }
        }
    }
    return true;//else bipartite graph
    } 
    bool dfscheck(int start , int colourVal , vector<int>&colour , vector<int>adj[]){
        //colour the node 
        colour[start]=colourVal;//initially colourVal is 0 
        for(auto adjacentNode:adj[start]){
            
            //colour adjacentNode with opposite colour of node if not yet coloured 
           if(colour[adjacentNode]==-1){
               //dfs call with opposite colourVal i.e !colourVal
               //if while calling it returned false return false
            if (dfscheck(adjacentNode,!colourVal,colour,adj)==false) {
                return false;
            }
           }
           //else when both neighbours have same colour not a bipartite graph 
           else if(colour[adjacentNode]==colourVal) {
               return false;
           }
        }
     return true;//else bipartite graph
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>colour(V,-1);//-1 indicates not yet coloured
	    //for multiple component
	    for(int i=0;i<V;i++){
	        //if not coloured
	        if(colour[i]==-1){ 
	            //while calling if at any time it returned falsed that means not a bipartite graph 
	            
	            /*using BFS */
	        //    if(bfscheck(i,colour,adj)==false){
	        //        return false;
	        //    }
	        
	           /*using DFS */
	           //initially,colourVal is 0 
	           if(dfscheck(i,0,colour,adj)==false){
	                return false;
	            }
	        }
	    }
	    return true;//else bipartite graph
	}

};
