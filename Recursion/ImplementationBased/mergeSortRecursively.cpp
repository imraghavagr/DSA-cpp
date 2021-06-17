#include<iostream>
using namespace std;
void merge(int *a, int s, int e){
	int mid = (s+e)/2;
	int i = s;
	int j = mid+1;
	int k = s;

	int temp[100];
	while(i<= mid & j <= e){
		if(a[i]<a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
		}
	}
	while(i<=mid){
		temp[k++] = a[i++];
	}
	while(j<=e){
		temp[k++] == a[j++];
	}

	//we need to copy all element to original array
	for(int i = s; i<=e; i++){
		a[i] = temp[i];
	}
}
void recMergeSort(int a[], int s, int e){

	//base case - if there is 1 or 0 elements, thans we do not need to sort them
	if(s>=e){
		return;
	}

	//rec case

	//follow 3 steps

	//step 1 : divide
	int mid = (s+e)/2;
	//step 2 : Recursive sort
	recMergeSort(a,s,mid);
	recMergeSort(a,mid+1,e);
	//step3: Merge the two sorted parts
	merge(a,s,e);
}
int main(){

	int arr[] = {5,6,1,2,4,0};
	int n = sizeof(arr)/sizeof(int);

	recMergeSort(arr,0,n-1);
	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
