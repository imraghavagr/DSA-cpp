#include<iostream>
using namespace std;
void sieve(int* arr){
	arr[2] = 1;

	for(int i = 3; i<1001; i+=2){
		arr[i] = 1;
	}

	for(int i = 3; i*i<1001; i+=2){
		if(arr[i]){
			for(int j = i*i; j<1001; j+=i){
				arr[j] = 0;
			}
		}
	}
}
int main(){
	int arr[1001] = {0};
	int n;
	cin>>n;
	sieve(arr);
	for(int i = 2; i<=n; i++){
		if(arr[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}