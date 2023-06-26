/*
Algorithm for Postfix to Infix: 

1.  Read the Prefix expression from left to right
2.  If the symbol is an operand, then push it onto the Stack.
3.  If the symbol is an operator, then pop two operands from the Stack 
    Create a string by concatenating the two operands and the operator between them. 
    string = (operand2 + operator + operand1) 
    And push the resultant string back to Stack
4.  Repeat the above steps until the end of Prefix expression.
5.  At the end stack will have only 1 string i.e resultant string

TC -> O(n) SC -> O(n)
*/
#include<iostream>
using namespace std;
string postToInfix(string &exp) {
    // Write your code here
    stack<string> stk; 
    for(auto ch : exp){
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <='z')){
            stk.push(string(1,ch));
        }
        else{
            string operend1 = stk.top();    stk.pop();
            string operend2 = stk.top();    stk.pop();
            stk.push("(" + operend2 + ch + operend1 + ")");
        }
    }
    string ans = stk.top(); stk.pop();
    return ans;
}
int main()
{
    return 0;
}