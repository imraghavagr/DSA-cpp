#include<iostream>
using namespace std;
//no repeating chars means .. size of map shoud be euqal to len of window 
int lengthOfLongestSubstring(string s) {
    //sliding window question 
    int i = 0, j = 0;
    unordered_map<char,int> mp;
    int ans = 0;
    while(j<s.length()){
        //calculation
        mp[s[j]]++;
        
        //mp.size() > j-i+1 => this condition will never be true .. so no need to mention it 
        if(mp.size() == j-i+1){
            ans = max(ans,j-i+1);
            j++;
        }
        else{
            //this means mp.size() < j-i+1 => chars are repeating in the window 
            while(mp.size() < j-i+1){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    return 0;
}