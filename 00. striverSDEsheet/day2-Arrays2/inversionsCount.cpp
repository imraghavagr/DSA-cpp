#include<iostream>
using namespace std;
void merge(long long arr[], long long int temp[], int s, int mid, int e, long long int &ans){
    int r1 = s;
    int r2 = mid+1;
    int w = s;
    while(r1<=mid || r2<=e){
        if(r1>mid){
            //arr1 is exhausted
            temp[w++] = arr[r2++];
        }
        else if(r2 > e){
            //arr2 is exhausted
            temp[w++] = arr[r1++];
        }
        else{
            if(arr[r1] <= arr[r2]){s
                temp[w++] = arr[r1++];
            }
            else{
                temp[w++] = arr[r2++];
                ans += (mid-r1)+1;
            }
        }
    }
    //now put back the elements from temp into the original array 
    for(int i = s; i<=e; i++){
        arr[i] = temp[i];
    }
}
void mergeSort(long long arr[],long long int temp[], long long s, long long e, long long int &ans){
    ///base case
    if(s == e)  return;
    
    //divide and sort
    int mid = s + (e-s)/2;
    mergeSort(arr, temp, s, mid, ans);
    mergeSort(arr, temp, mid+1, e, ans);
    
    //merge the sorted arrays back 
    merge(arr, temp, s, mid, e, ans);

}
// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    //we will use merge sort
    long long ans = 0;
    long long int temp[N];
    mergeSort(arr, temp, 0, N-1, ans);
    return ans;
}
int main()
{
    return 0;
}