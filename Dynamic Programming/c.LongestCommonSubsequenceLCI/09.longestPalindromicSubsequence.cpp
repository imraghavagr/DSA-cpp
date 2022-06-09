//given a string s, return the length of largest palindromic subsequence that can be formed from it.

#include<iostream>
#include<algorithm>
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
int solution(string s){
    //lps of s = LCS(s,reverse(s))
    string b = s;
    reverse(b.begin(),b.end());
    return LCS(s,b,s.length(),b.length());
}
int main()
{   
    string s;
    cin>>s;
    cout<<solution(s)<<endl;
    return 0;
}