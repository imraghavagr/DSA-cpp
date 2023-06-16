#include<iostream>
using namespace std;
int firstOccurence(int *arr, int n, int x){
    int ans = -1; 
    int s = 0, e = n-1; 
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == x){
            ans = mid;
            e = mid-1;
        }
        else if(x < arr[mid]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}
int lastOccurence(int *arr, int n, int x){
    int ans = -1; 
    int s = 0, e = n-1; 
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == x){
            ans = mid;
            s = mid+1;
        }
        else if(x < arr[mid]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}
int count(int arr[], int n, int x) {
    int firstOcc = firstOccurence(arr, n, x);
    int lastOcc = lastOccurence(arr, n, x);
    if(firstOcc == -1 && lastOcc == -1){
        return 0;
    }
    else if(firstOcc == -1) return 1; 
    else if(lastOcc == -1)  return 1; 
    else    return (lastOcc - firstOcc)+1;
}
//Approach 2 - using stl
int count(int arr[], int n, int x) {
    if(binary_search(arr, arr+n, x)){
        int idx1 = lower_bound(arr, arr+n, x) - arr;
        int idx2 = upper_bound(arr, arr+n, x) - arr;
        return idx2-idx1;
    }
    else    return 0;
}
int main()
{
    return 0;
}