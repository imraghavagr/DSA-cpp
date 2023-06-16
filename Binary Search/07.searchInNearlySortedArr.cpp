#include<iostream>
using namespace std;
//modified Binary Search 
int searchInNearlySorted(vector<int> &arr, int target){
    //the elemnt that should be at k, can be found at index, k-1, k or k+1 
    int s = 0, e = arr.size()-1; 
    while(s<=e){
        int mid = s + (e-s)/2;
        if(target == arr[mid])  return mid; 
        if(mid > s && target == arr[mid-1])   return mid-1;
        if(mid < e && target == arr[mid+1])   return mid+1;

        if(target > arr[mid]){
            //target will lie in right half 
            s = mid + 2;
        }
        else{
            e = mid - 2;
        }
    }
    return -1; 
}
int main()
{
    return 0;
}