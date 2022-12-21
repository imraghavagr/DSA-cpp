#include<iostream>
using namespace std;
void primeSieve(int* arr){
	//special cases
	arr[2] = 1;

	//mark all odds as potential primes
	for(int i = 3; i<1001; i+=2){
		arr[i] = 1;
	}

	for(int i = 3; i*i<1001; i+=2){
		if(arr[i]){
			for(long long j = i*i; j<1001; j+=i){
				arr[j] = 0;
			}
		}
	}
}
int main()
{	
	//marking all numbers as non prime
	int arr[1001] = {0};

	primeSieve(arr);

	int n;
	cin>>n;

	for(int i = 2; i<=n; i++){
		if(arr[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}