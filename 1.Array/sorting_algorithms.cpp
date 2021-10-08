#include<iostream>
using namespace std;

void input(int a[],int n){
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
}

void output(int a[], int n){
	for(int i = 0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void selection_sort(int a[], int n){
	for(int i=0; i<n-1;i++){
		int min_idx = i, flag = 0;;
		//find out the smallest element in the unsorted array
		for(int j=i; j<n; j++){
			if(a[j] < a[min_idx]){
				min_idx = j;
				flag = 1;
			}
		}
		if(flag == 1)
			swap(a[i], a[min_idx]);
	}
}

void bubble_sort(int a[], int n){

	//N-1 large elements to the end.
	for(int i = 1; i <= n-1; i++){
		for(int j = 0; j<n-i; j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}

void insertion_sort(int a[], int n){
	//putting n-1 elements into thier 'right' position in the sorted part
	for(int i = 1; i<=n-1; i++){
		int e = a[i];
		int j = i-1; 
		while(j>=0 && a[j] > e){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = e;
	}
}

int main(){
	
	int a[100], n;
	cin>>n;
	input(a,n);

	/*selection_sort(a,n);
	output(a,n);

	bubble_sort(a,n);
	output(a,n);*/

	insertion_sort(a,n);
	output(a,n);

	return 0;
}