#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverseOnlyLetters(string s) {
	int i = 0; 
	int j = s.length()-1;
	if(s.length() == 1)	 return s;

	while(i<=j){
		if(isalpha(s[i]) and isalpha(s[j])){
			swap(s[i],s[j]);
			i++;
			j--;
		}
		if(!isalpha(s[i])){
			i++;
		}
		if(!isalpha(s[j])){
			j--;
		}
	}
	return s;
}

int main(){
	string s = "a-bC-dEf-ghIj" ;
	s = reverseOnlyLetters(s);
	cout<<s<<endl;
	return 0;
}