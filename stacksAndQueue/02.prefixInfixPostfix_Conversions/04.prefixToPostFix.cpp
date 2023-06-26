/*
Algorithm for Prefix to Postfix:

1.  Read the Prefix expression in reverse order (from right to left)
2.  If the symbol is an operand, then push it onto the Stack
3.  If the symbol is an operator, then pop two operands from the Stack 
    Create a string by concatenating the two operands and the operator after them. 
    string = operand1 + operand2 + operator 
    And push the resultant string back to Stack
4.  Repeat the above steps until end of Prefix expression.
5.  At the end, only ans string will be left into the stack 
*/
#include<iostream>
using namespace std;
string preToPost(string s) {
    stack<string> stk; 
    for(int i = s.length()-1; i>=0; i--){
        if(isalpha(s[i])){
            stk.push(string(1,s[i]));
        }
        else{
            //s[i] is an operator 
            //we need to form operend1 + operand2 + operator 
            string operend1 = stk.top(); stk.pop();
            string operend2 = stk.top(); stk.pop();
            string temp = operend1 + operend2 + s[i];
            stk.push(temp);
        }
    }
    string ans = stk.top(); stk.pop();
    return ans;
}
int main()
{
    return 0;
}