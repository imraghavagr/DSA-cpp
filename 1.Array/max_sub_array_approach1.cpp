// 13 for the following array: 
// 1 3 -2 6 2 -1 4
#include <iostream>
#include <climits>
#include <algorithm>
#define endl '\n'
using namespace std;
void solve(int *a, int n){
    int sum = 0;
    int ans = INT_MIN;
    int start, end;
    for(int i = 0; i<n; i++){
        sum = 0;
        for(int j = i; j<n; j++){
            sum += a[j];
            if(sum > ans){
                ans = sum;
                start = i;
                end = j;
            }
        }
    }
    cout<<ans<<endl;
    for(int i = start; i<=end; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int a[] = {-4,1,3,-2,6,2,-1,4,-7};
    //int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(int);
    int maxSum = 0;
    int left,right;
    for(int i =0; i<n; i++){
        for(int j =i; j<n; j++){
            //we got all possible pairs of i and j
            //print the continuos numbers between those pairs
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum += a[k];
                //cout<<a[k]<<",";
            }
            //cout<<" ";
            //maxSum = max(sum,maxSum);
            if(sum>maxSum){
                maxSum = sum;
                left = i;
                right = j;
            }
        }
        //cout<<endl;
    }
    cout<<maxSum<<" for the following array: "<<endl;
    for(int i = left; i<=right; i++){
        cout<<a[i]<<" ";
    }
    solve(a,n);
    return 0;
}

        


