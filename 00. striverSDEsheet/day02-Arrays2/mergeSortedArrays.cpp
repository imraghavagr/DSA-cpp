#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//https://leetcode.com/problems/merge-sorted-array/description/

//O(m+n)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //we will maintain three pointers 
    //r1, r2, w
    int r1 = m-1;
    int r2 = n-1;
    int w = (m+n)-1;

    while(r1>=0 || r2>=0){
        if(r1<0){
            //nums1 is exhausted 
            nums1[w--] = nums2[r2--];
        }
        else if(r2<0){
            //nums2 is exhausted 
            nums1[w--] = nums1[r1--];
        }
        else{
            //both the choices are present 
            nums1[w--] = nums1[r1]>nums2[r2] ? nums1[r1--] : nums2[r2--];
        }
    }
}

//for gfg question - another variation 
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
//N = n1(size of a1) + n2 (size of a2)
//O(n*mlogm)
//O(n1) for traversal of a1 * O(n2logn2) sorting the array a2 of size n2
void mergeAndSort1(vector<int> &a1,vector<int> &a2){
    for(int i = 0; i<a1.size(); i++){
        //compare this element with the 0th element of a2 array
        if(a1[i]>a2[0]){
            swap(a1[i],a2[0]);
            //but now a2 is unsorted, so sort it again
            sort(a2.begin(),a2.end());
        }
    }
}
//O(m*n)
void mergeAndSort2(vector<int> &a1, vector<int> &a2, int n, int m){
    if(n<m){
        mergeAndSort2(arr2, arr1, m, n);
    }
    
    //now arr1 is the longer array with size n
    //and arr2 is the smaller array with size m 
        
    /*
    1. traverse arr1 from left to right 
    2. if(arr1[i] > arr2[0])
            swap(arr1[i], arr2[0])
            
            //but now arr2 is unosorted, so we will sort it before moving to next step 
            //and for sorting we will use insertion sort ..that will here work in O(m)
    */
    
    for(int i = 0; i<n; i++){
        if(arr1[i] > arr2[0]){
            swap(arr1[i], arr2[0]);
            // sort(arr2, arr2+m);
            //instead of using inbuilt sort just use insertion sort to reduce time 
            //from mlogm to m 
            int first = arr2[0];
            //traverse from index 1 to m-1 in arr2 and put num in the correct position 
            int j;
            for(j = 1; j<m && arr2[j]<first; j++){
                arr2[j-1] = arr2[j];
            }
            arr2[j-1] = first;
        }
    }
}
//Optimal Method - O(m+n+mlogm+nlogn) -> O(mlogm + nlogn)
/*
keep one pointer at the end of arr1 and another at first element of arr2 

*/
//gap method - 
void mergeOptimal(vector<int> a1, vector<int> a2){

}
int main()
{   
    vector<int> a1 = {1,4,7,8,10};
    vector<int> a2 = {2,3,9};
    mergeAndSort1(a1,a2);
    for(int x : a1){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int x : a2){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
