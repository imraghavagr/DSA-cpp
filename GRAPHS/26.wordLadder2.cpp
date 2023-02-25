//https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii
//gamd fatt gayi bhaiya :D
#include<iostream>
using namespace std;
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    // code here
    vector<vector<string>> ans;
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    int level = 0;
    
    vector<string> stringsUsedOnLevel; // we will store all the strings that are getting matched.. 
    //such that we can remove them from the set once a level is finished. 
    stringsUsedOnLevel.push_back(beginWord);
    
    while(!q.empty()){
        vector<string> v = q.front();
        q.pop();
        //if i am on a newer level, the size of v will excced level
        if(v.size() > level){
            level++;
            //now once this level is finished.. 
            //erase all the strings that were matched in previous level from the set 
            for(auto it : stringsUsedOnLevel){
                st.erase(it);
            }
            //also clear the stringsUsedOnLevel vector
            stringsUsedOnLevel.clear();
        }
        string word = v.back(); //same as v[v.size()-1]; 
        if(word == endWord){
            if(ans.size() == 0){
                //this means we got the first sequence
                ans.push_back(v);
            }
            else if(ans[0].size() == v.size()){
                //if it is not the first sequence, then we have earlier got any sequence 
                //which is already stored at ans[0]
                //since we only want the min transformation answers, we will only consider this...
                //one if its size is same as our first ans sequence
                ans.push_back(v);
            }
        }
        
        //now try to change the chars of word 
        for(int i = 0; i<word.length(); i++){
            char originalChar = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    //push it into the queue with its sequence 
                    v.push_back(word);
                    q.push(v);
                    //also this is begin used on this level 
                    //so add it to the stringUsedOnLevel vector 
                    stringsUsedOnLevel.push_back(word);
                    //bat -> this became bat, pat .. 
                    //again change it back to bat 
                    //such that next time it can be made bat, bot.. 
                    v.pop_back();
                }
            }
            word[i] = originalChar;
        }
    }
    return ans;
}
int main()
{

    return 0;
}