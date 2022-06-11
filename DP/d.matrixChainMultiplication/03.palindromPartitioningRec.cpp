#include<iostream>
#include<climits>
using namespace std;
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
    int ans = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int tempans = 1 + solve(s,i,k)+ solve(s,k+1,j);
        ans = min(ans,tempans);
    }
    return ans;
    
}
int palindromicPartition(string str)
{
    int n= str.length();
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