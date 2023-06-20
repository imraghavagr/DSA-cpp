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
//Optimal approach = Binary Search 
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
    int n1 = nums1.size(), n2 = nums2.size();
    int s = 0, e = n1;
    while(s<=e){
        int mid = (s+e) >> 1;
        //for the left half, we will take mid number of elements from nums1 and N - mid elements from nums2.
        int cut1 = mid; 
        int cut2 = (n1+n2+1)/2 - mid;

        int l1 = (cut1 == 0) ? INT_MIN :  nums1[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN :  nums2[cut2-1];
        int r1 = (cut1 == nums1.size()) ? INT_MAX :  nums1[cut1];
        int r2 = (cut2 == nums2.size()) ? INT_MAX :  nums2[cut2];
        
        if(l1 <= r2 && l2 <= r1){
            //this partion is valid 
            if((n1+n2)&1){
                return max(l1, l2);
            }
            else{
                return (double)(max(l1, l2) + min(r1, r2))/2;
            }
        }
        else if(l1 > r2){
            e = mid -1; 
        }
        else{
            s = mid + 1;
        }
    }
    return 0.0; 
}
int main()
{
    return 0;
}