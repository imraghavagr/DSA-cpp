#include<iostream>
using namespace std;

//check if array is sorted or not using recursion

bool isSorted(int a[], int n){

	//base case 
	if(n == 0 or n == 1){ return true; }

	//rec case
	//soln for current problem 
	//base address of the remaining array will be a+1
	if(isSorted(a+1,(n-1)) and a[0]<a[1]){ return true; }

	return false;


}

int main(){

	int a[]= {1,2,7,4,5};
	int n = sizeof(a)/sizeof(int);

	if(isSorted(a,n)){
		cout<<"Given array is sorted"<<endl;
	}
	else{
		cout<<"Given array is not sorted"<<endl;
	}



	return 0;
}
