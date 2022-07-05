#include<bits/stdc++.h>
using namespace std;
bool bs(int* arr, int n, int key){
	if(key<arr[0] || key>arr[n-1]){
		return false;
	}
	int s = 0;
	int e = n-1;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(key == arr[mid]){
			return true;
		}
		else if(key> arr[mid]){
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	return false;
}
int main()
{
	int t,q;
	cin>>t>>q; // t- no. of seats sold, q- no of seets that reena likes 
	int arr1[t];
	for(int i = 0; i<t; i++){
		cin>>arr1[i];
	}
	sort(arr1,arr1+t);
	for(int i = 0; i<q; i++){
		int n;
		cin>>n;
		//check if this number n is present in arr1 or not
		if(bs(arr1,q,n)){
			//seat already filled 
			cout<<"N"<<endl;
		}
		else{
			cout<<"Y"<<endl;
		}
	}
	return 0;
}
