#include<iostream>
using namespace std;

int storeAllOccurrences(int *a, int i,int n, int key, int *b, int j){
	
	//base case
	if(i == n){
		return j;
	}

	//rec case
	if( a[i] == key){
		b[j] = i;
		storeAllOccurrences(a,i+1,n,key,b,j+1);
	}
	else{
		storeAllOccurrences(a,i+1,n,key,b,j);
	}		

}

int main(){

	int arr[100000];
	int n;
	cin>>n;

	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	int key;
	cin>>key;

	int out[n];

	int cnt = storeAllOccurrences(arr,0,n,key,out,0);
	
	for(int i = 0; i<cnt; i++){
		cout<<out[i]<<" ";
	}
	cout<<endl;

	return 0;
}
