//https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
#include<iostream>
using namespace std;
int search(string pat, string txt) {
    // code here
    int i = 0, j = 0;
    int k = pat.length();
    int ans = 0;
    unordered_map<char,int> mp;
    for(int i = 0; i<k; i++){
        mp[pat[i]]++;
    }
    int count = mp.size();
    
    while(j<txt.length()){
        //calculation
        if(mp.find(txt[j]) != mp.end()){
            mp[txt[j]]--;
            if(mp[txt[j]] == 0) count--;
        }
        //build the window
        if(j-i+1 < k){
            j++;
        }
        //window size achieved
        else if(j-i+1 == k){
            //1. find ans from calc
            if(count == 0)  ans++;
            
            //2. remove calculation for the element that will be left out while sliding
            if(mp.find(txt[i]) != mp.end()){
                mp[txt[i]]++;
                if(mp[txt[i]] == 1){
                    count++;
                }
            }
            //3. slide the window
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    return 0;
}