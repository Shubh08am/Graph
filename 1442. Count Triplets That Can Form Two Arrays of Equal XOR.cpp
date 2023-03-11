class Solution {
public:
    int countTriplets(vector<int>& arr) { 
        /*
         a==b --> a^b==b^b --> a^b==0
        */
        int xorr = 0 , n = arr.size() , ans=0 ; 
        for(int i=0;i<n;i++){ 
           xorr=0; //reset it 
            for(int j=i;j<n;j++){
             xorr = (xorr^arr[j]) ; 
             if(xorr==0){
            //  cout<<i<<" "<<j<<"\n"; 
              //all elements of that window(i to j) can be considered :- window size :- j-i+1 
              // divide in 2 part in j-i ways
              ans+=(j-i);
            }
     }
    }
        return ans;
    }
};
