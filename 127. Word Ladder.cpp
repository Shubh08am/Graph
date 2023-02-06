class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //bfs appraoch as level wise 
        //set also works
        unordered_set<string>s(wordList.begin(),wordList.end());//stores all word 
        queue<pair<string,int>>q;
        //push beginWord with step=1 in queue
        int step=1; 
        q.push({beginWord,step}); 
         //erase beginWord from set 
         s.erase(beginWord);
         
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second ; 
            q.pop();
            //see if end word found 
            if(word==endWord){
                return step;
            }
            for(int i=0;i<word.size();i++){
                char original = word[i] ; 

                //replace ch with a to z and see which word exist in set 
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    //see if word exist in set 
                    if(s.find(word)!=s.end()){
                        //it exist remove from set as found 
                        s.erase(word); 
                     /* we can return answer from here as well 
                        //see if end word found 
                     if(word==endWord){
                       return step+1; //counted this step as well
                     }
                     */
                        //push in queue with increment in step 
                        q.push({word,step+1});
                    }
                }
                //replace word[i] after we are done with changing it from a to z by original char which was there in it
            word[i] = original;   
            }
        }
        return 0;//if not found
    }
};
