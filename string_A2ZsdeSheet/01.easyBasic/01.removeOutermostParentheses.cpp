#include<iostream>
using namespace std;
string removeOuterParentheses(string s) {
    string ans; 
    //whenever stack is empty we have one valid decomposition 
    int cnt = 0; 
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(') cnt++; 
        else    cnt--;            
        if((cnt > 0 && s[i] == ')') || (cnt > 1 && s[i] == '('))    ans.push_back(s[i]);
    }
    return ans; 
}
int main()
{
    return 0;
}