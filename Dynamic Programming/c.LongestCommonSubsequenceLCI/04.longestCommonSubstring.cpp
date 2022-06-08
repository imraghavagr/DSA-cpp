//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#
#include<iostream>
using namespace std;
int longestCommonSubstr (string text1, string text2, int m, int n)
{
    int t[m+1][n+1];
    
    // initialization
    for(int j =0; j<n+1; j++){
        t[0][j] = 0;
    }
    for(int i = 1; i<m+1; i++){
        t[i][0] = 0;
    }

    for(int i = 1; i<m+1; i++){
        for(int j =1; j<n+1; j++){
            if(text1[i-1]==text2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = 0;
            }
        }
    }
    int ans = -1;
    for(int i =0;i<m+1; i++){
        for(int j = 0; j<n+1; j++){
            ans = max(ans,t[i][j]);
        }
    }
    return ans;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int m = s1.length();
    int n = s2.length();
    cout<<longestCommonSubstr(s1,s2,m,n)<<endl;
    return 0;
}