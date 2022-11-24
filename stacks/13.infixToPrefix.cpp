#include <bits/stdc++.h>
using namespace std;

//this func will check if the current char is an operator or not
bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c));
}

// Function to find priority of given operator
int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	return 0;
}

string infixToPrefix(string infix)
{
	// stack for operators.
	stack<char> operators;

	// stack for operands or values
	stack<string> operands;

	for (int i = 0; i < infix.length(); i++) {
		
        if (infix[i] == '(') {
			operators.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (!operators.empty() &&
				operators.top() != '(') {
				string op1 = operands.top();
				operands.pop();
				string op2 = operands.top();
				operands.pop();
				char op = operators.top();
				operators.pop();
				string tmp = op + op2 + op1;
				operands.push(tmp);
			}
			operators.pop();
		}
		else if (!isOperator(infix[i])) {
			operands.push(string(1, infix[i]));
		}
		else {
			while (!operators.empty() && getPriority(infix[i]) <= getPriority(operators.top())) {

				string op1 = operands.top();
				operands.pop();

				string op2 = operands.top();
				operands.pop();

				char op = operators.top();
				operators.pop();

				string tmp = op + op2 + op1;
				operands.push(tmp);
			}

			operators.push(infix[i]);
		}
	}
	while (!operators.empty()) {
		string op1 = operands.top();
		operands.pop();

		string op2 = operands.top();
		operands.pop();

		char op = operators.top();
		operators.pop();

		string tmp = op + op2 + op1;
		operands.push(tmp);
	}

	// Final prefix expression will be present on the top of the operand stack
	return operands.top();
}
int main()
{
	// string s = "(5-6)*7";
    string s = "(A-B/C)*(A/K-L)";

	cout << infixToPrefix(s)<<endl;
	return 0;
}
