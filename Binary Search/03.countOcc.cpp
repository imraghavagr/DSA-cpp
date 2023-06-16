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
int main()
{
    return 0;
}