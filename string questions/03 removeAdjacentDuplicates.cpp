#include<iostream>
#include<string>
#include<stack>
using namespace std;

//since this can be done in O(n2) by brute force and the inner loop depends upon outer loop
//this must be solved by stack also 
void soln(string s){
    stack<char> stk;
    for(int i = s.length()-1; i>=0; i--){
        //traverse the string from right to left
        //if stack is empty or the current element is not equal to top, push the current element 
        //in other cases do not push it
        if(stk.empty()) stk.push(s[i]);
        else if(stk.top() != s[i]) stk.push(s[i]);
    }
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
    cout<<endl;
}
int main()
{   
    string s = "Raagghhaavvv";
    soln(s);
    return 0;
}