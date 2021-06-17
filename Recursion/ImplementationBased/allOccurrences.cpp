#include<iostream>
using namespace std;

void allOccurrences(int *a, int i, int n, int key){

	//base case
	if(i == n){
		return;
	}

	//rec case
	if(a[i] == key){ cout<<i<<" ";}
	allOccurrences(a,i+1,n,key);
}

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

	int arr[] = {1,2,3,7,8,7,5,7,8};
	int n = sizeof(arr)/sizeof(int);
	int key = 7;
	int out[n];
	allOccurrences(arr,0,n,key);
	cout<<endl;

	int cnt = storeAllOccurrences(arr,0,n,key,out,0);
	cout<<cnt<<endl;
	for(int i = 0; i<cnt; i++){
		cout<<out[i]<<" ";
	}
	cout<<endl;

	return 0;
}
