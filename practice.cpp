#include<iostream>
using namespace std;
int main()
{
	string s1 = "Hellor";
	string s2 = "heLLo";
	if(toupper(s1[0]) == toupper(s2[0])){
		cout<<"Equal"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}