#include<iostream>
using namespace std;
//optimal approach => binary search approach 
//time => O(log(min(n,m))), space => O(1)
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{   
    if(n > m)   return kthElement(arr2, arr1, m, n, k);
    
    int s = max(0, k - m), e = min(k, n); 
    
    while(s <= e){ 
        int mid = s + (e-s)/2;
        int cut1 = mid, cut2 = k - mid; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];
        
        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        if(l1 > r2) e = mid - 1;
        else    s = mid + 1;
    }
    return 0; 
}
int main()
{
    return 0;
}