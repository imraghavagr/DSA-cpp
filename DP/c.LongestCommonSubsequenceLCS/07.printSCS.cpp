//https://leetcode.com/problems/shortest-common-supersequence/
//given two strings, print the shortest common supersequence among them
//if there are multiple valid answers, return any 1
#include<iostream>
#include<algorithm>
using namespace std;
string printSCS(string text1, string text2) {
    //let m,n be the size of text1 and text2 respectively
    int m = text1.length();
    int n = text2.length();
    
    int t[m+1][n+1];
    
    for(int i = 0; i<m+1; i++){
        for(int j =0; j<n+1; j++){
            if(i==0||j==0){
                t[i][j] = 0;
            }
        }
    }
    for(int i = 1; i<m+1; i++){
        for(int j =1; j<n+1; j++){
            if(text1[i-1]==text2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    int i=m,j=n;
    string s;
    while(i>0 && j>0) {
        if(text1[i-1] == text2[j-1])
        {
            s.push_back(text1[i-1]);
            i--;
            j--;
        } else {
            if(t[i][j-1] >= t[i-1][j]) {
                s.push_back(text2[j-1]);
                j--;
            } else {
                s.push_back(text1[i-1]);
                i--;
            }
        }
    }
    //i ya j me se kisi me agar values rah jaengi to following while loops se unhe bhi le lenge ans me
    while(i > 0) {
        s.push_back(text1[i-1]);
        i--;
    }
    
    while(j > 0) {
        s.push_back(text2[j-1]);
        j--;
    } 
    
    reverse(s.begin(), s.end());
    return s;

}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<printSCS(s1,s2)<<endl;
    return 0;
}