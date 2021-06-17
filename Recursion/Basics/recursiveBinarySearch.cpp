#include<iostream>
using namespace std;

int recBinSearch(int a[], int key, int l, int r){

	int mid = (l+r)/2;
	
	//base case
	if(l>r) { return -1; }	
	if(key == a[mid]){ return mid; }
	
	//rec case
	if(key<a[mid]){ recBinSearch (a,key,l,mid-1); }
	else if(key>a[mid]){ recBinSearch(a,key,mid+1,r); }
}

int main(){

	int arr[] = {1,2,3,4,5,6,8,9,10};
	int n = sizeof(arr)/sizeof(int);
	
	int key = 3;

	int l = 0;
	int r = n-1;

	if (key < arr[l] or key > arr[r]){
		cout<<-1<<endl;
	}
	else{
		cout<<recBinSearch(arr,key,l,r)<<endl;
	}
	return 0;
}

