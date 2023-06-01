//given two strings a and b.. return if a is a subsequence of b or not? 
#include<iostream>
using namespace std;
int LCS(string a, string b, int m, int n){
    int t[m+1][n+1];
    for(int j = 0; j<=n; j++){
        t[0][j] = 0;
    }
    for(int i = 1; i<=m; i++){
        t[i][0] = 0;
    }
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(a[i-1]==b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[m][n];
}
bool patternMatching(string a, string b){
    int lcs = LCS(a,b,a.length(),b.length());
    return lcs==a.length();
}
int main()
{   
    string a,b;
    cin>>a>>b;
    cout<<patternMatching(a,b)<<endl;
    return 0;
}