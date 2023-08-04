#include<iostream>
using namespace std;
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> mp; 
    int ans = 0; 
    int i = 0, j =0; 
    while(j < s.size()){
        mp[s[j]]++; 
        if(mp.size() == j-i+1){
            ans = max(ans, j-i+1);
            j++; 
        }
        else{
            //this means mp size < window size 
            while(mp.size() < j-i+1){
                mp[s[i]]--; 
                if(mp[s[i]] == 0)   mp.erase(s[i]);
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