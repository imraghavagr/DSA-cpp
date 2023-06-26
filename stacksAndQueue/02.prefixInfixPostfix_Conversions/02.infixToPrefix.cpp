/*
Step 1: Reverse the infix expression. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.

Step 2: Convert the reversed infix expression to “nearly” postfix expression.
i.e. while converting to postfix expression, instead of using pop operation to pop operators with greater than or equal precedence, 
here we will only pop the operators from stack that have greater precedence.

Step 3: Reverse the postfix expression.

*/
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

int prec(char ch){
    if(ch == '^')   return 3; 
    else if(ch == '*' || ch == '/') return 2; 
    else if(ch == '+' || ch == '-') return 1; 
    else    return -1;
}
string infixToNearlyPostfix(string s) {
    string ans = "";
    stack<char> stk; 
    for(auto ch : s){
        if(ch == '('){
            stk.push(ch);
        }
        else if(isalpha(ch) || isdigit(ch)){
            //append it to the answer
            ans += ch; 
        }
        else if(ch == ')'){
            //pop all the elements and add them to ans untill "(" is encountered 
            while(stk.top() != '('){
                ans += stk.top();
                stk.pop();
            }
            //pop the "(" also 
            stk.pop();
        }
        else{
            //this means ch is an operator
            while(!stk.empty() && prec(ch) < prec(stk.top())){
                ans += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }
    //pop out all the remainign elements 
    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }
    return ans; 
    
}
string reverseStr(string s){
    int i = 0, j = s.length()-1; 
    while(i<j){
        if(s[i] == '(' && s[j] == ')'){
            i++, j--;
        }
        else if(s[i] == '('){
            swap(s[i], s[j]);
            s[j] = ')';
            i++, j--;
        }
        else if(s[i] == ')'){
            swap(s[i], s[j]);
            s[i] = '(';
            i++, j--;
        }
        else{
            swap(s[i++], s[j--]);
        }
    }
    return s; 
}
string infixToPrefix(string &s){
    string reversedString = reverseStr(s);
    cout<<reversedString<<endl;
    string postFixExpression = infixToNearlyPostfix(reversedString);
    reverse(postFixExpression.begin(), postFixExpression.end());
    return postFixExpression;
}
int main()
{      
    // string s = "(A+(B*C)^D)";
    string s = "a+b*c-d/e";
    cout<<infixToPrefix(s)<<endl;
    return 0;
}