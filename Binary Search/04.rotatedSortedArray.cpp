//A sorted array was right rotated k times, given the rotated version of the array, find k. 
#include<iostream>
using namespace std;
int findKRotation(int arr[], int n) {
    int s = 0, e = n-1; 
    while(s<=e){
        int mid = s + (e-s)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(arr[mid] < arr[prev] && arr[mid] < arr[next]){
            return mid;
        }
        else if(arr[mid] < arr[0]){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return 0;
}

int main()
{
    return 0;
}