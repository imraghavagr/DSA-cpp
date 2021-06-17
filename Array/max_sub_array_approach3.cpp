#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;
	int a[1000];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	//Kadane's Algorithm for maximum subarray sum
	int curr_sum = 0, max_sum = 0;

	for(int i=0; i<n; i++){
		curr_sum += a[i];
		if(curr_sum < 0){
			curr_sum = 0;
		}
		if(curr_sum > max_sum )
			max_sum = curr_sum;
	}
	cout<<max_sum;

	return 0;
}