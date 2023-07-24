#include<iostream>
using namespace std;
bool isPossible(int mid, vector<int> &arr, int numStudents){
    int reqStudents = 1; 
    int booksAllocated = arr[0];
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] > mid)    return false; 
        booksAllocated += arr[i];
        if(booksAllocated > mid){
            reqStudents++; 
            booksAllocated = arr[i];
        }
        if(reqStudents > numStudents)   return false;
    }
    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m > n)   return -1;
    int start = *min_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1; 
    while(start <= end){
        int mid = start + (end-start)/2; 
        if(isPossible(mid, arr, m)){
            ans = mid; 
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    return 0;
}