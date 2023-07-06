//https://leetcode.com/problems/palindrome-partitioning/description/
#include<iostream>
using namespace std;
bool isPalindrome(string &s, int start, int end){
    int i = start;
    int j = end;
    while(i<=j){
        if(s[i] != s[j])    return false;
        i++;
        j--;
    }
    return true;
}
void solve(int index, string &s, vector<string> &op, vector<vector<string>> &ans){
    if(index == s.length()){
        ans.push_back(op);
        return;
    }
    for(int i = index; i<s.length(); i++){
        //check if the partitioning from index to i is possilbe 
        if(isPalindrome(s, index, i)){
            op.push_back(s.substr(index, i-index+1));
            solve(i+1, s, op, ans);
            op.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> op;
    solve(0, s, op, ans);
    return ans;
}
int main()
{
    return 0;
}