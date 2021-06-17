//sort(containerStart,containerStart+n);
#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
	//descending order 
	return a>b;
}
int main(){

	int arr[] = {20,45,23,35,64,753,75,0};

	int n = sizeof(arr)/sizeof(int);

	//ascending order by default
	sort(arr,arr+n); // arr+n is not inclusive

	for(int i =0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	//for sorting in descending order
	sort(arr,arr+n, compare);
	for(int i =0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
