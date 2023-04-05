//https://leetcode.com/problems/median-of-two-sorted-arrays/
#include<iostream>
using namespace std;
//Approach 1 - merge both the sorted arrays and directly fetch the median 
//o(m+n) time o(m+n) space
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> temp(m+n);
    int r1 = 0;
    int r2 = 0;
    int w = 0;
    while(r1<n || r2<m){
        if(r1>=n){
            temp[w++] = nums2[r2++];
        }
        else if(r2>=m){
            temp[w++] = nums1[r1++];
        }
        else{
            temp[w++] = nums1[r1]<=nums2[r2]? nums1[r1++] : nums2[r2++];
        }
    }
    if(temp.size()&1){
        //odd length
        return (double)temp[temp.size()/2];
    }
    else{
        int a = temp[temp.size()/2];
        int b = temp[temp.size()/2-1];
        return ((double)a+(double)b)/2;
    }
}
int main()
{
    return 0;
}