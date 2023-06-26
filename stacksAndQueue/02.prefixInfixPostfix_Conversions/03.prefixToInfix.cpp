/*
Algorithm for Prefix to Infix: 

1.  Read the Prefix expression in reverse order (from right to left)
2.  If the symbol is an operand, then push it onto the Stack
3.  If the symbol is an operator, then pop two operands from the Stack 
    Create a string by concatenating the two operands and the operator between them. 
    string = (operand1 + operator + operand2) 
    And push the resultant string back to Stack
4.  Repeat the above steps until the end of Prefix expression.
5.  At the end stack will have only 1 string i.e resultant string

TC -> O(n) SC -> O(n)
*/
#include<iostream>
using namespace std;
string preToInfix(string s) {
    stack<string> stk; 
    //iterate from back to front of the given expression
    for(int i = s.length()-1; i>=0; i--){
        //if curr char is alphabet, push into the stack 
        if(isalpha(s[i]) || isdigit(s[i])){
            stk.push(string(1,s[i]));
        }
        else{
            //if curr char is an operator, pop top two elements 
            //form string temp = (operend1 operator operend2) and push back into stk 
            string op1 = stk.top();   stk.pop();
            string op2 = stk.top();   stk.pop();
            // concat the operands and operator
            string temp = "(" + op1 + s[i] + op2 + ")";
            // Push string temp back to stack
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