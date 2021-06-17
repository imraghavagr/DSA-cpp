//custom comparator for bubbleSort()

#include<iostream>
using namespace std;
bool compare(int a, int b){
	return a>b;
}
void bubble_sort(int a[], int n, bool (&cmp)(int a, int b)){

	//N-1 large elements to the end.
	for(int i = 1; i <= n-1; i++){
		for(int j = 0; j<n-i; j++){
			if(cmp(a[j], a[j+1])){
				swap(a[j],a[j+1]);
			}
		}
	}
}
int main(){

	int arr[] = {20,45,23,35,64,753,75,0};

	int n = sizeof(arr)/sizeof(int);

	bubble_sort(arr,n,compare);

	for(int i =0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
