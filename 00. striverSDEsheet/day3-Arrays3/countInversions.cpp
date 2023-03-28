#include<iostream>
using namespace std;
void merge(long long *arr, int s, int mid, int e, long long &ans, long long *temp){
    int r1 = s;
    int r2 = mid+1;
    int w = s;
    while(r1<=mid || r2<=e){
        if(r1>mid){
            //nums1 is exhausted
            temp[w++] = arr[r2++];
        }
        else if(r2>e){
            //nums2 is exhausted 
            temp[w++] = arr[r1++];
        }
        else{
            //both the options are present
            if (arr[r1] <= arr[r2]) {
              temp[w++] = arr[r1++];
            } 
            else{
                ans += (mid - r1) + 1;
                temp[w++] = arr[r2++];
            }
        }
    }
    //now copy back vaues from temp into original array 
    for(int i = s; i<=e; i++){
        arr[i] = temp[i];
    }    
}
void mergeSort(long long *arr, int s, int e, long long &ans, long long *temp){
    if(s == e) return;
    //divide 
    int mid = s + (e-s)/2;

    //divid the array into two and sort them individually 
    mergeSort(arr, s, mid, ans, temp);
    mergeSort(arr, mid+1, e, ans, temp);

    //now merge back both the sorted arrays 
    merge(arr, s, mid, e, ans, temp);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long ans = 0;
    long long temp[n];
    //merge sort technique 
    mergeSort(arr,0, n-1, ans, temp);
    return ans;
}
int main()
{
    return 0;
}