#include<iostream>
using namespace std;
int partitionArr(int *arr, int s, int e){
	int i = s;
	int j = e; 
	int pivot = arr[s];
	while(i<j){		
		while(arr[i] <= pivot && i <= e-1)	i++;
		while(arr[j] > pivot && j >= s+1)	j--; 
		if(i<j)	swap(arr[i], arr[j]);
	}
	swap(arr[s], arr[j]);
	return j; 
}
void applyQuickSort(int *arr, int s, int e){
	if(s >= e)	return; 
	//put pivot in correct pos (partition index) and put smaller and equal elements to left and 
	//larger to right
	int partitionIdx = partitionArr(arr, s, e);
	applyQuickSort(arr, s, partitionIdx-1);
	applyQuickSort(arr, partitionIdx+1, e);
}
void quickSort(int input[], int start, int end) {
	applyQuickSort(input, start, end);
}
int main()
{
    return 0;
}