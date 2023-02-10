class Solution {
public:
    void dfs(unordered_map<string,int>&freq,vector<vector<string>>&ans,vector<string>&curr,string &word ,string &beginWord){
        if(word == beginWord) {
            //we,reached first level i.e beginWord which is our answer 
            //answer stored in reverse order from end to begin 
            reverse(curr.begin(),curr.end());
            ans.push_back(curr);
            //now,backtrack and again reverse curr 
            // reverse again so that the dfs calls are not disturbed.
             reverse(curr.begin(),curr.end());
             return;
        }
        int curr_level = freq[word] , n = word.size(); 
        for(int i=0;i<n;i++){
             char original = word[i];
              for(char ch='a' ; ch<='z' ; ch++){
                  word[i]=ch;
                  //word exist in map and value at previous level of new word also exist 
                   int next_level = freq[word]+1;
                  if(freq.count(word) && next_level==curr_level){
                      curr.push_back(word);
                      dfs(freq,ans,curr,word,beginWord);
                      // pop the current word from the back of the queue to traverse other possibilities.
                    curr.pop_back();
                  }
                 }
               word[i] = original ; //restore
            }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) { 
        vector<vector<string>>ans;
        unordered_map<string,int>freq;
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<string>q;
         int n = beginWord.size();
        q.push(beginWord);
        // beginWord initialised with level 1.
        freq[beginWord] = 1;
        //remove beginWord from set as used 
        s.erase(beginWord);

        while(!q.empty()){
            string word = q.front();
            q.pop();
            int curr_level = freq[word] ; 

            //answer found 
            if(word==endWord) break;

            //change word every char from a to z 
            for(int i=0;i<word.size();i++){
              char original = word[i];
              for(char ch='a' ; ch<='z' ; ch++){
                  word[i]=ch;
                  //if present in set 
                  if(s.count(word)){
                      q.push(word);
                      s.erase(word);
                      //at new level , this word is pushed 
                      int next_level = curr_level+1;
                      freq[word] = next_level;
                  }
              }
               word[i] = original ; //restore
            }
        }
       
       //if endWord is found 
       if(freq.count(endWord)){
           vector<string>curr;
           curr.push_back(endWord); //answer will be stored in reverse order here from end to begin 
           //dfs call 
           dfs(freq,ans,curr,endWord,beginWord);
       }
       return ans;
    }
};
