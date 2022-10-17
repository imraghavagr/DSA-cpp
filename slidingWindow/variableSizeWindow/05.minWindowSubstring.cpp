//https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
//https://leetcode.com/problems/minimum-window-substring/

#include<iostream>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;
int smallestWindow (string s, string p)
{
    // Your code here
    int i=0,j=0;
    int ans = INT_MAX;
    unordered_map<char,int> mp;
    for(int i = 0; i<p.length(); i++){
        mp[p[i]]++;
    }
    int start,end;
    int count = mp.size();
    while(j<s.length()){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0){
                count--;
            }
        }

        if(count == 0){
            // ans = min(ans,j-i+1);
            while(count==0){
                if(ans>j-i+1){ // right now we will get the least starting index ans, if we put ans>= j-i+1 => we will get the max starting index ans.... 
                    ans = j-i+1;
                    start = i;
                    end = j;
                }
                if(mp.find(s[i]) == mp.end()){
                    //this char is not present in map, and hence is not required in our window
                    i++;
                }
                else{
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)   count++;
                    i++;
                }
            }
        }
        j++;
    }
    for(int k = start; k<=end; k++){
        cout<<s[k];
    }
    cout<<endl;
    return ans;
    
}

// In case there are multiple answers, i.e. multiple such windows of same length, return the one with the least starting index. 
//timetopractice 
//ans1 - toprac
//ans2 - opract


int main()
{   
    string s = "timetopractice";
    string p = "toc";
    cout<<smallestWindow(s,p)<<endl;
    return 0;
}