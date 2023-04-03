// https://www.interviewbit.com/problems/matrix-median/
#include<iostream>
using namespace std;
int helperBinarySearch(vector<int> &arr, int key){
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] <= key) low = mid+1;
        else    high = mid-1;
    }
    return low;
}
int findMedian(vector<vector<int> > &A) {
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();
    while(low<=high){
        int mid = low + (high-low)/2;
        //now find the number of elements less than equal to mid using a different binary search 
        int cnt = 0;
        for(int i = 0; i<n; i++){
            cnt += helperBinarySearch(A[i], mid);
        }
        if(cnt > (n*m)/2){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main()
{
    return 0;
}