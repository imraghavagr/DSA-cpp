#include<iostream>
using namespace std;

int * fun(){
	/*
	int a = {1,2,3,4,5};
	cout<<a<<endl; // address of first block of array lets say - 'xyz'
	cout<<a[0]<<endl; //1

	//we should never return a local variable
	//as it will be free up from the memory once the func call is over

	return a; */

	//if we want to return it for some reason we can use dynamic array
	int *a = new int[5]{0};
	 cout<<a<<endl; // xyz
	 cout<<a[0]<<endl; //0
	 return a;
}

int main(){

	int *b = fun();
	cout<<b<<endl; // xyz
	cout<<b[0]<<endl; //0

	//let us clear the array a 
	delete [] b;
	return 0;
}
