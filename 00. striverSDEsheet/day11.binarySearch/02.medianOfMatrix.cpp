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

//same approach, just used upper_bound for finding number of elements less than equal to mid
int helperBS(vector<vector<int>> &matrix, int m, int n, int mid){
    //search for cnt of elements <=mid in each row 
    int cnt = 0; 
    for(int i = 0; i<m; i++){
        cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
    }
    return cnt;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int s = 1, e = 1e5; 
    int m = matrix.size(); 
    int n = matrix[0].size();
    while(s<=e){
        int mid = s + (e-s)/2; 
        //cnt the number of elements <= mid 
        int cnt = helperBS(matrix, m, n, mid);
        if(cnt > (m*n)/2)   e = mid - 1;
        else s = mid + 1;
    }
    return s; 
}
int main()
{
    return 0;
}