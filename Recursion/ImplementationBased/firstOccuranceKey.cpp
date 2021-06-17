#include<iostream>
using namespace std;

int firstOcc(int a[], int n, int key){

	//base case
	//n = 0 means we have checked if all the elements
	//and element is not found
	if(n == 0){
		return -1;
	}
	
	//rec case
	if(a[0] == key){
		return 0;
	}
	int i = firstOcc(a+1,n-1,key);
	if(i == -1){
		return -1;
	}
	return i+1;
}

int firstOcc2(int a[],int i, int n, int key){

	//base case
	if(i == n){
		return -1;
	}
	//rec case
	if( key == a[i]){
		return i;
	}
	return firstOcc2(a, i+1, n, key);


}

int main(){
	
	int arr[] = {1,2,3,4,5,6,7,8,7,9};
	int n = sizeof(arr)/sizeof(int);
	int key = 7;
	cout<<firstOcc(arr,n,key)<<endl;
	int i = 0;
	cout<<firstOcc2(arr,i,n,key)<<endl;
	return 0;
}
