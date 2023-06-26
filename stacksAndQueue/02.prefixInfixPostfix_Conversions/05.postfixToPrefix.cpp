/*
Algorithm to convert given postfix expression to prefix expression

1.  Read the Postfix expression from left to right

2.  If the symbol is an operand, then push it onto the Stack

3.  If the symbol is an operator, then pop two operands from the Stack 
    Create a string by concatenating the two operands and the operator before them. 
    string = operator + operand2 + operand1 
    And push the resultant string back to Stack

4.  Repeat the above steps until end of Postfix expression.
*/
#include<iostream>
using namespace std;
//we need to form: operator + operend2 + operend1
string postToPre(string s) {
    stack<string> stk; 
    //traverse from left to right
    for(auto ch : s){
        if(isalpha(ch)){
            stk.push(string(1,ch));
        }
        else{
            //ch is an operator 
            string operend1 = stk.top();    stk.pop();
            string operend2 = stk.top();    stk.pop();
            string temp = ch + operend2 + operend1;
            stk.push(temp);
        }
    }
    string temp = stk.top();    stk.pop();
    return temp;
}
int main()
{
    return 0;
}