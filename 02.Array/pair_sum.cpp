#include<iostream>
#include<algorithm>
using namespace std;

//Given a SORTED Array, find the pair of elements that sum to k(given)
int main(){

	int n,k;
	int a[] = {1,3,4,2,5};
	k = 5;
	n = sizeof(a)/sizeof(int);
	sort(a,a+n);

	int i = 0, j=n-1;
	while(i<j){
		int curr_sum = a[i] + a[j];
		if(curr_sum > k){
			j--;
		}
		else if(curr_sum < k){
			i++;
		}
		else if(curr_sum == k){
			cout<<a[i]<< " and " <<a[j]<<endl;
			i++;
			j--;
		}
	}
	return 0;
}
