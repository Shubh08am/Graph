//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<vector<string>>ans;
        vector<string>curr,usedOnLevel;
        int level = 0 ; 
        
        while(!q.empty()){
            curr = q.front();
            q.pop();
            //remove all words from previous level from set 
            if(curr.size()>level){
                level++;
                for(auto word : usedOnLevel){
                    s.erase(word);
                }
            }
        
        //take last word from curr and change it from a to z and keep checking 
        string word = curr.back(); 
        if(word==endWord){
        //check for answer :- first time 
        if(ans.size()==0) ans.push_back(curr);
        //after that take only that sequence which has same length as ans[0].size()
        else if( ans[0].size() == curr.size()) ans.push_back(curr);
        }
        for(int i=0;i<word.size();i++){
            char original = word[i] ; 
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                //if, word is present in set than take
                if(s.find(word)!=s.end()){
                    curr.push_back(word);
                    q.push(curr) ; //a sequence found
                    usedOnLevel.push_back(word);//a word we used and will remove after this level end 
                    //back-track i.e remove last added word from curr 
                    curr.pop_back();
                }
            }
            word[i]=original;//restored
        } 
        }
    return ans;
    }
};
