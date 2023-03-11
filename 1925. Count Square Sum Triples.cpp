class Solution {
public:
    int countTriples(int n) {
        int ans = 0 ; 
        for(int i=1;i<=n;i++){
          for(int j=i+1;j<=n;j++){ 
              double y = sqrt(j*j+i*i) ; 
            if(y==floor(y) && y<=n) {
                ans+=2;
                }
        }}
        return ans;
    }
};
