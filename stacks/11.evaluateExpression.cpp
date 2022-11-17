#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;

int applyOperation(int a, int b, char operation){
    switch (operation)
    {
    case '+':
        return a+b;
        break;
    
    case '-':
        return a-b;
        break;
    
    case '*':
        return a*b;
        break;
    
    default:
        return a/b;
        break;
    }
}
int precedence(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    if(ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}
int solve(string s){
    
    stack<char> operationStack;
    stack<int>  valueStack;

    for(int i = 0; i<s.length(); i++){
        if(isdigit(s[i])){
            //it can be a greater than 1 digit number also .. so we need to find the entire number written there in that string 
            int val = 0;
            int len = 0;
            while(isdigit(s[i])){
                len++;
                i++;
            }
            i = i - len;
            int multiply = (int)pow(10,len-1);
            while(isdigit(s[i])){
                val = val + (s[i] - '0')*multiply;
                multiply/=10;
                i++;
            }
            //now push it into the stack
            valueStack.push(val);
            
            i--;
        }
        else if(s[i] == '('){
            operationStack.push(s[i]);
        }
        else if(s[i] == ')'){
            //this means solve the entire operation  untill "(" is encountered in the operationStack
            while(!operationStack.empty() && operationStack.top() != '('){
                int right = valueStack.top();
                valueStack.pop();
                int left = valueStack.top();
                valueStack.pop();
                char ch = operationStack.top();
                operationStack.pop();
                int ans = applyOperation(left, right, ch);
                //now push this ans into values stack
                valueStack.push(ans);
            }
            //if while loop terminated because of encountering '(', pop it, as this (...) is solved 
            if(!operationStack.empty()){
                operationStack.pop();
            }
        }
        else{
            //means it is an operator 

            //precendce also matters here
            //find an operator whose precedence is smaller than the current opeation
            while(!operationStack.empty() && precedence(operationStack.top()) >= precedence(s[i])){
                //this means take two values from the value stack and take this operation 
                int right = valueStack.top();
                valueStack.pop();
                int left = valueStack.top();
                valueStack.pop();
                char ch = operationStack.top();
                operationStack.pop();
                int ans = applyOperation(left, right, ch);
                //now push this value into the value stack again 
                valueStack.push(ans);
            }
            //now push the current operator into the operation stack
            operationStack.push(s[i]);
            
        }

    }

    //now apply the remaining ops
    while(!operationStack.empty()){
        int right = valueStack.top();
        valueStack.pop();
        int left = valueStack.top();
        valueStack.pop();
        char ch = operationStack.top();
        operationStack.pop();
        valueStack.push(applyOperation(left,right,ch));
    }
    return valueStack.top();
}
int main()
{   
    string s;
    cin>>s;

    cout<<solve(s)<<endl;
    return 0;
}