#include<iostream>
#include<cstring>
using namespace std;

int toInt(char ch[], int len){
	//base case
	if(len == 0){
		return 0 ;
	}

	//rec case
	int digit = ch[len-1] - '0'; //last digit
	int small_ans = toInt(ch,len-1);
	
	return small_ans*10 + digit;
}

int main(){

	char ch[] = "1234";
	int l = strlen(ch);
	int num = toInt(ch,l);
	cout<<num<<endl;
	cout<<num+1<<endl;
	return 0;
}
