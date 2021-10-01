#include<iostream>
using namespace std;

int binary_search(int a[], int n, int key){
	if((key<a[0]) | (key>a[n])){
		return -1;
	}
	int s = 0, e = n-1;
	while(s<=e){
		int mid = (s+e)/2;
		if(key == a[mid]){
			return mid;
		}
		else if(key < a[mid]){
			e = mid-1;
		}
		else if(key > a[mid]){
			s = mid+1;
		}
	}
	return -1;
}
int main(){

	int a[100], n, key;
	cin>>n;

	for(int i = 0; i < n; i++){
		cin>>a[i];
		cout<<a[i]<<" ";
	}
	cout<<endl;

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