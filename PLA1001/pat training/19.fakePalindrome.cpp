#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
bool solve(string s){
    unordered_map<char, int> mp;
    for(int i = 0; i<s.length(); i++){
        mp[s[i]] += 1;
    }
    bool oddFound = false;
    for(auto it : mp){
        if((it.second&1) && oddFound){
            return false;
        }
        if(it.second & 1){
            oddFound = true;
        }
    }
    return true;
}
int main()
{      
    string s;
    cin>>s;
    vector<string> v;
    //generate all substrings 
    for(int i = 0; i<s.length(); i++){
        string temp;
        for(int j = i; j<s.length(); j++){
            temp += s[j];
            v.push_back(temp);
        }
        temp.clear();
    }
    //now check if any permutation of a given string can be a palindrome or not 
    for(auto it : v){
        if(solve(it)){
            cout<<it<<" ";
        }
    }
    cout<<endl;
    return 0;
}