#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(n);

	int key1 = 5;
	auto it = find(arr, arr+n, key1);
	int idx = it - arr;
	if(idx == n){
		cout<<"Key not found"<<endl;
	}
	else{
		cout<<"key found at position "<<idx+1<<endl;
	}

	int key2 = 11;
	it = find(arr, arr+n, key2);
	idx = it - arr;
	if(idx == n){
		cout<<"Key not found";
	}
	else{
		cout<<"key found at position "<<idx+1<<endl;
	}



	return 0;
}
