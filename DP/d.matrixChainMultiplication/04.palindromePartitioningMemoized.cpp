//this code can still be optimized lil bit .. it will work on gfg.. but maybe fails in IB. 
//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#

#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int t[501][501]; //globally declare dp matrix.. assuming str.length<500
bool isPalindrome(string &s,int i, int j){
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
    
    if(i>=j){
        return 0;
    }
    if(isPalindrome(s,i,j)){
        return 0;
    }

    if(t[i][j] != -1){
        return t[i][j];
    }

    int ans = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int tempans = 1 + solve(s,i,k)+ solve(s,k+1,j);
        ans = min(ans,tempans);
    }
    return t[i][j] = ans;
    
}
int palindromicPartition(string str)
{
    int n= str.length();
    memset(t,-1,sizeof(t));
    //pass the string by reference => One optimization. 
    return solve(str,0,n-1);
    
}
int main()
{
    string s;
    cin>>s;
    cout<<palindromicPartition(s)<<endl;
    return 0;
}