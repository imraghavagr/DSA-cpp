#include<iostream>
#include<string>
using namespace std;
int longestCommonSubsequence(string s1,string s2, int m, int n){
    static int t[1001][1001];
    memset(t,-1,sizeof(t));

    //base case
    if(m==0 || n==0){
        return 0;
    }
    if(t[m][n] != -1){
        return t[m][n];
    }

    //rec case
    if(s1[m-1] == s2[n-1]){
        return t[m][n] = 1+longestCommonSubsequence(s1,s2,m-1,n-1);
    }
    else{
        return t[m][n] = max(longestCommonSubsequence(s1,s2,m-1,n),longestCommonSubsequence(s1,s2,m,n-1));
    }    
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int m = s1.length();
    int n = s1.length();
    cout<<longestCommonSubsequence(s1,s2,m,n)<<endl;
    return 0;
}