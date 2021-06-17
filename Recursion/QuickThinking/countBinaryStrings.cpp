#include<iostream>
using namespace std;

int f(int n){

	//base case
	if(n == 0 ){return 1;}
	if(n == 1){ return 2; }

	//rec case
	//when first digit is 0
	return f(n-1)+f(n-2);
}

int main(){

	int n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}
