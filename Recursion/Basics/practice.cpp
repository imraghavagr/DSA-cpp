#include<iostream>
using namespace std;

int factorial(int n){
	//base case
	if(n == 0 or n == 1)
	return 1;

	//rec case 
	return n*factorial(n-1);
}
int main(){
	
	int n;
	cin>>n;
	cout<<factorial(n)<<endl;
	return 0;

}
