//instead of printing the length of lcs, print the lcs itself
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string printLCS(string x, string y) {
    //let m,n be the size of x and y respectively
    int m = x.length();
    int n = y.length();
    
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
            if(x[i-1]==y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    //once the table for len(lcs) question is formed, backtrack from t[m]n] to t[0][0] to get the ans
    int i = m;
    int j = n;
    string ans;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                //go left
                j--;
            }
            else{
                //go up
                i--;
            }
        }
    }
    reverse (ans.begin(),ans.end());
    return ans;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<printLCS(s1,s2)<<endl;
    return 0;
}