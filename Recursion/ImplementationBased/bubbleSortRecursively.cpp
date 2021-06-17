#include<iostream>
using namespace std;

void bubble_sort(int *a, int n){

	//base case
	if(n == 1){
		return;
	}

	//we will make the call in the unsorted part of the array
	for(int j = 0;j<n-1; j++){
		if(a[j]>a[j+1]){
			swap(a[j],a[j+1]);
		}
	}
	bubble_sort(a,n-1);
}
void bubble_sort2(int *a, int n, int j){
	//this one is completely recursive
	//no for loop

	//base case
	if(n==1){
		return;
	}
	if(j  == n-1){
		//single passs of the current array has been done
		return bubble_sort2(a,0,n-1);
	}
	//rec case
	if(a[k] > a[j+1]){
		swap([a[j],a[j+1]]);
	}
	bubble_sort2(a,j+1,n);
	return;\
}

int main(){

	int a[] = (5,4,3,1,2);
	int n = 5;




	return 0;
}

