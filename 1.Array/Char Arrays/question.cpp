//given a string l
//l = "1234 ab+cd", 
//l contains one number(in string form) and one pattern (pattern is the operations to be done on numbers)
// separated by space 
//the pattern will contain one operator- '+' or '-'. Do the operation on the number according to the pattern
//and return the integer result. 
//eg-> 
// ip = 1234 ab+cd
// op = 46 (12+34)
#include<bits/stdc++.h>
using namespace std;
int solve(string line){
	int n = line.length();	
	int lenNumber = line.find(" ");
	string number = line.substr(0,lenNumber);
	string pattern = line.substr(lenNumber+1, n-lenNumber);
	int posOfOper = pattern.find('+');
	if(posOfOper == -1){
		posOfOper = pattern.find('-');
	}
	// cout<<posOfOper<<" "<<pattern[posOfOper]<<" "<<number<<" "<<pattern<<endl;
	// cout<<number<<" "<<pattern<<" "<<lenNumber<<" "<<posOfOper<<endl;
	int leftOperand = stoi(number.substr(0,posOfOper));
	int rightOperand = stoi(number.substr(posOfOper,pattern.length()-posOfOper-1));
	if(pattern[posOfOper] == '-'){
		return leftOperand-rightOperand;
	}
	else{
		return leftOperand+rightOperand;
	}
}
int main(){
	string line;
	cin>>line;
	cout<<solve(line)<<endl;
	return 0;
}