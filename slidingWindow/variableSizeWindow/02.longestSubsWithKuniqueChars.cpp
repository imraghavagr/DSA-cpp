//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
#include<iostream>
using namespace std;
int longestKSubstr(string s, int k) {
    int i = 0, j = 0; 
    int ans = INT_MIN; 
    unordered_map<char, int> mp;
    while(j<s.length()){
        //some calculation
        mp[s[j]]++;
        if(mp.size() < k){
            j++;
        }
        else if(mp.size() == k){
            ans = max(ans, (j-i)+1);
            j++;    
        }
        else{
            while(mp.size() > k)    {
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size() == k){
                ans = max(ans, (j-i)+1);
            }
            j++;
        }
    }
    return ans == INT_MIN ? -1 : ans;
}
int main()
{
    return 0;
}