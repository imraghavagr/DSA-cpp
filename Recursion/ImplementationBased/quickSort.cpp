#include<iostream>
using namespace std;
int partition(int *a, int s, int e){

	//inplace - no extra array - using two pointer approach
	int i = s-1; //that is -1 in the very begining..then 1 step behing j
	int j = s;
	
	int pivot = a[e];
	for(; j<=e-1;){
		if(a[j]<=pivot){
			//merge the smaller element in the region - 1
			i+=1;
			swap(a[i],a[j]);
		}
		//expand the larger region
		j = j+1;
	}

	//place the pivot element in the correct index
	swap(a[i+1],a[e]);

	return i+1;

}
void quickSort(int *a, int s, int e){
	
	//base case
	if(s>=e){
		return;
	}

	//rec case
	int p = partition(a,s,e);
	//left part
	quickSort(a,s,p-1);
	//right part
	quickSort(a,p+1,e);

}
int main(){

	int arr[] = {2,7,8,6,1,5,4};
	int n = sizeof(arr)/sizeof(int);

	quickSort(arr,0,n-1);

	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
