//works with sorted arrays
#include<iostream>
#include<algorithm>
using namespace std;

int binary_search(int a[], int n, int key){
	
	if(key<a[0] | key>a[n-1]){
		return -1;
	}
	int start = 0;
	int end = n-1;
	int mid;

	while(start<=end){
		mid = (start+end)/2;
		if(a[mid] == key){ return mid;}
		else if(key<a[mid]){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return -1;

}
int main(){

	int a[] = {1,2,3,4,5,6,7,9,10};
	int n = sizeof(a)/sizeof(int);
	int key;
	cin>>key;
	int ans = binary_search(a,n,key);
	if(ans == -1){
		cout<<"Key not found"<<endl;
	}
	else{
		cout<<"Key found at index "<<ans<<endl;
	}
	return 0;
}