//https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#
#include<iostream>
using namespace std;

int solve(string &s, int i, int j, bool isTrue){
    //base condition
    if(i>j) return false;//0
    
    if(i==j){
        //check that we require to find num of ways for true or false
        if(isTrue == true){
            //when we needed to find for true 
            //we will return true if this last char (at i==j) is T
            return s[i] == 'T';
        }
        else{
            //when we needed to find for false 
            //we will return true if this last char is false
            return s[i] == 'F';
        }
    }
    long int ans = 0;
    for(int k = i+1; k<=j-1; k+=2){
        int lt = solve(s,i,k-1,true);
        int lf = solve(s,i,k-1,false);
        int rt = solve(s,k+1,j,true);
        int rf = solve(s,k+1,j,false);
        
        //find ans from temp answers

        if(s[k]=='&'){
            if(isTrue == true){
                ans+= lt*rt;
            }
            else{
                ans += (lf*rf) + (lt*rf) + (lf*rt);
            }
        }
        else if(s[k]=='|'){
            if(isTrue == true){
                ans += (lt*rt) + (lt*rf) + (lf*rt);
            }
            else{
                ans += lf*rf;
            }
        }
        else if(s[k] == '^'){
            if(isTrue == true){
                ans += (lt*rf) + (lf*rt);
            }
            else{
                ans += (lt*rt) + (lf*rf);
            }
        }
        
    }
    return ans;
}

int countWays(int N, string S){
    // code here
    return solve(S,0,N-1,true);
}
int main()
{   
    string s;
    cin>>s;
    int N = s.length();
    cout<<countWays(N,s)<<endl;
    return 0;
}