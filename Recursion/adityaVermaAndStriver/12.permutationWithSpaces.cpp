#include<iostream>
using namespace std;
void solve(string ip, string op, vector<string> &ans){
    if(ip.length() == 0){
        ans.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    //now we have two choices - take with space take without space 
    
    //take with space 
    op1.push_back(' ');
    op1.push_back(ip[0]);
    
    //take without space 
    op2.push_back(ip[0]);
    
    //now make the input smaller 
    ip.erase(ip.begin()+0);
    
    solve(ip, op1, ans);
    solve(ip, op2, ans);
}
vector<string> permutation(string S){
    // Code Here
    vector<string> ans;
    string op = "";
    op.push_back(S[0]);
    S.erase(S.begin()+0);
    solve(S, op, ans);
    return ans;
}
int main()
{
    return 0;
}