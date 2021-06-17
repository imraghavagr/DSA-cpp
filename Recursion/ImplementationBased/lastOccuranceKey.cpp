#include<iostream>
using namespace std;
int lastOcc(int a[], int n, int key){

	//base case
	if(n == 0){
		return -1;
	}

	//rec  case
	int i = lastOcc(a+1,n-1,key);
	if(i != -1){
		return i+1;
	}
	if(a[0] == key){
		return 0;
	}
	else{return -1;}

}
int main(){
	
	int arr[] = {1,2,3,4,5,6,10};
	int n = sizeof(arr)/sizeof(int);
	int key = 7;
	cout<<lastOcc(arr,n,key)<<endl;
	return 0;
}
