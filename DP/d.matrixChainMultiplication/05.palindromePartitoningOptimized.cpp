//More optimized code
//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#
/*
    We are only checking for solve(i,j)-> that, if it has been already stored in t matrix or not
    When, solve(i,j) is not solved, maybe either solve(i,k) or solve(k+1,j) or both are solved earlier.
    So, now we will also store the values left = solve(i,k) and right = solve(k+1,j) in t matrix.
*/
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int t[501][501]; //globally declare dp matrix.. assuming str.length<500
bool isPalindrome(string &s, int i, int j){
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int solve(string &s, int i, int j){
    if(i>=j)return 0;
    if(t[i][j]!=-1)return t[i][j];
    if(isPalindrome(s,i,j))return 0;
    int ans = INT_MAX;
    for(int k = i; k<=j-1;k++){
        int left,right;
        if(t[i][k]!=-1){
            left = t[i][k];
        }
        else{
            left = solve(s,i,k);
        }
        if(t[k+1][j]!=-1){
            right = t[k+1][j];
        }
        else{
            right = solve(s,k+1,j);
        }
        int tempans = left+right+1;
        ans = min(ans,tempans);
    }
    return t[i][j]=ans;
}
int palindromicPartition(string str)
{
    // code here
    memset(t,-1,sizeof(t));
    int n = str.length();
    return solve(str,0,n-1);
}
int main()
{
    string s;
    cin>>s;
    cout<<palindromicPartition(s)<<endl;
    return 0;
}