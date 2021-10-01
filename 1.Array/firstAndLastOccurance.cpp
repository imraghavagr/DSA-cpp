#include<iostream>
using namespace std;

int first_occurance(int a[], int n, int key){

		int s = 0;
		int e = n-1;
		int ans = -1;
		if(key<a[s] || key >a[e]){
			return -1;
		}
		//update in a dirn that answer value gets lower and lower
		while(s<=e){
			int mid = (s+e)/2;
			if(a[mid] == key){
				ans = mid;
				e = mid - 1;
			}
			else if(a[mid] > key){
				e = mid -1;
			}
			else{
				s = mid+1;
			}
		}
		return ans;
}
int last_occurance(int a[], int n, int key){

		int s = 0;
		int e = n-1;
		int ans = -1;
		if(key<a[s] || key >a[e]){
			return -1;
		}
		//update in a dirn that answer value gets lower and lower
		while(s<=e){
			int mid = (s+e)/2;
			if(a[mid] == key){
				ans = mid;
				s = mid+1;
			}
			else if(a[mid] > key){
				e = mid -1;
			}
			else{
				s = mid+1;
			}
		}
		return ans;
}
int main(){

	int a[] = {1,3,5,8,8,8,8,12,15,20};
	int n = sizeof(a)/sizeof(int);

	int key;
	cin>>key;

	//first and last occurance of a key in sorted array
	int fo = first_occurance(a, n, key);
	if(fo == -1){
		cout<<"Key not found "<<endl;
	}
	else{
		cout<<"Key found at index "<<fo<<endl;
	}

	//last occurance
	int lo = last_occurance(a, n, key);
	if(lo == -1){
		cout<<"Key not found "<<endl;
	}
	else{
		cout<<"Key found at index "<<lo<<endl;
	}



	return 0;
}
