#include<iostream>
using namespace std;

int main(){

	//1st way to initialise 2D character array
	char a[][10] = {{'a','b','c','\0'}, {'d', 'e', '\0'}};

	//2nd way
	char b[][10] = {"abc", "def", "ghi"};

	cout<<a<<endl;  //garbage value
	cout<<b<<endl; //garbage value

	cout<<a[0]<<endl;
	cout<<a[1]<<endl;

	cout<<b[0]<<endl;
	cout<<b[1]<<endl;
	cout<<b[2]<<endl;
	return 0;
}
