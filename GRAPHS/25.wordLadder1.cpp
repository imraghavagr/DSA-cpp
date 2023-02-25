//https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder
#include<iostream>
using namespace std;
//time - O(N)*(word.length*26)
//space - O(N) + O(N) -> O(N)
int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    // Code here
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string,int>> q;
    q.push({startWord, 1});
    //since we pushed startWord, remove it from the set (this acts as marking as visited)
    st.erase(startWord);
    
    //O(N), N- wordList.length();
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        //time = O(word.length * 26)
        for(int i = 0; i<word.size(); i++){
            //try to change word[i] from a to z 
            char originalCh = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                //check if the changed word exists in the set 
                if(st.find(word) != st.end()){
                    if(word == targetWord){
                        return steps+1;
                    }
                    st.erase(word);
                    q.push({word, steps+1});
                }
            }
            //change back to original value 
            word[i] = originalCh;
        }
    }
    return 0;
}
int main()
{
    return 0;
}