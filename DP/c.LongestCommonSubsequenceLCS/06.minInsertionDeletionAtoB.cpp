/*
Given two strings a and b, return the number of insertions and deletions required to be done in a to convert it into b
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
*/
#include<iostream>
using namespace std;
int LCS(string s1,string s2,int m, int n){
    int t[m+1][n+1];
    for(int j = 0; j<n+1; j++){
        t[0][j] = 0;
    }
    for(int i = 1; i<m+1; i++){
        t[i][0] = 0;
    }
    
    for(int i =1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j] = 1+ t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[m][n];
}
int minOperations(string str1, string str2) 
{ 
    // Your code goes here
    int m = str1.length();
    int n = str2.length();
    int lcs = LCS(str1,str2,m,n);
    //deletions = m-lcs
    //insertions = n - lcs
    //total operations = m+n-2lcs
    return m+n-(2*lcs);
} 
int main()
{   
    string a;
    string b;
    cin>>a>>b;
    cout<<minOperations(a,b)<<endl;
    return 0;
}