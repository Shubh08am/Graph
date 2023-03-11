 class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here 
	    int n = matrix.size() ; 
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1)  matrix[i][j] = 1e9 ; 
	        if(i==j) matrix[i][j]==0;
	        }
	    }
	    
	    //Floyd Warshall Algorithm 
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	           for(int j=0;j<n;j++){
	               //if not reachable no use to try to visit 
	               // without it also run but it saves some time 
	              if(matrix[i][via]==1e9 || matrix[via][j]==1e9) continue;
	                //else update distance 
	                matrix[i][j] = min(matrix[i][j] , matrix[i][via]+matrix[via][j]) ;
	           }
	        }
	    }
	    
	    //if still 1e9 that means not reachable update t0 -1 
	    	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9)  matrix[i][j] = -1 ; 
	        }
 	    }
	}
};
