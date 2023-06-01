//longest repeating subsequence in a given string s is basically LCS(s,s) with restriction i!=j
//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
/*for eg.
i/p: s = aabebcdd
longest repeating subsuequence is "abd" with len = 3
o/p: 3
*/
#include<iostream>
using namespace std;
int LongestRepeatingSubsequence(string str){
    // Code here
    int n = str.length();
    int t[n+1][n+1];
    for(int j=0; j<n+1; j++){
        t[0][j]=0;
    }
    for(int i = 1; i<n+1; i++){
        t[i][0] = 0;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n;j++){
            if(str[i-1]==str[j-1] && i!=j) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1],t[i-1][j]);
            }
        }
    }
    return t[n][n];
}
int main()
{
    string s;
    cin>>s;
    cout<<LongestRepeatingSubsequence(s)<<endl;
    return 0;
}