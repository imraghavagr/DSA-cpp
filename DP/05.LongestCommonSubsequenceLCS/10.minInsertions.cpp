//given a string s, return the min number of insertions required to make it a pallindrome.
//https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
#include<iostream>
#include<algorithm>
using namespace std;
int LCS(string a, string b, int n){
    int t[n+1][n+1];
    for(int j = 0; j<n+1; j++){
        t[0][j] = 0;
    }
    for(int i = 1; i<n+1; i++){
        t[i][0] = 0;
    }
    
    for(int i =1; i<n+1; i++){
        for(int j = 1; j<n+1; j++){
            if(a[i-1]==b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][n];
}
int LPS(string a,int n){
    string b = a;
    reverse(b.begin(),b.end());
    return LCS(a,b,n);
}
int minDeletions(string str, int n) { 
    //complete the function here 
    //min number of deletions = len(str)-len(longest pallindromic subsequence)
    int lps = LPS(str,n);
    return n-lps;
} 
int minInsertions(string str,int n){
    //min number of insertions in a string to make it a palindrome is equal to that of deletions
    return minDeletions(str,n);
}
int main()
{   
    string s;
    cin>>s;
    int n = s.length();
    cout<<minInsertions(s,n)<<endl;
    return 0;
}