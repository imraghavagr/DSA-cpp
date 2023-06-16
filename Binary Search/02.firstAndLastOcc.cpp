#include<iostream>
using namespace std;
int firstOccurence(int *arr, int n, int x){
    int s = 0, e = n-1; 
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == x){
            ans = mid; 
            e = mid-1;  
        }
        else if(arr[mid] > x){
            e = mid - 1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}
int lastOccurence(int *arr, int n, int x){
    int s = 0, e = n-1;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == x){
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid] < x){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    int first, last; 
    first = firstOccurence(arr, n, x);
    last = lastOccurence(arr, n, x);
    return {first, last};
}
{
    return 0;
}