#include<iostream>
using namespace std;

int main(){

	int a[] = {-4,1,3,-2,6,2,-1,-4,-7};
	int n = sizeof(a)/sizeof(int);
	int max_sum = 0, curr_sum = 0;
	int left=-1, right=-1;

	int cum_sum[n];
	//building a cumulative sum array
	cum_sum[0] = a[0];
	for(int i=1; i<n; i++){
		cum_sum[i] = cum_sum[i-1] + a[i];
	}
	

	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			curr_sum = 0;
			curr_sum = cum_sum[j] - cum_sum[i-1];
			if(curr_sum>max_sum){
				max_sum = curr_sum;
				left = i;
				right = j;
			}
		}
	}
	cout<<"Maximum Sum = "<<max_sum<<endl;
	cout<<"Max Sum sub array is: ";
	for(int i = left; i<=right; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;


	return 0;
}
