//single 1D vector space optimized soln
#include<iostream>
using namespace std;
bool solve(vector<int> arr, int n, int sum){
    //space optimized approach 
    //dp[0] will be 1 (because of empty subset)
    vector<int> dp(sum+1, 0);
    //filling the remaining cells
    for(int i = 1; i<=n; i++){
        for(int j = sum; j>=0; j--){
            dp[0] = 1;
            if(arr[i-1] <= j){
                //two choices - include or not include 
                bool c1 = dp[j-arr[i-1]];
                bool c2 = dp[j];
                dp[j] = c1||c2;
            }
            else{
                //single choice - do not choose the element 
                dp[j] = dp[j];
            }
        }
    }
    return dp[sum];
}
bool isSubsetSum(vector<int>arr, int sum){
    // code here 
    int n = arr.size();
    return solve(arr,n, sum);
}
int main()
{
    return 0;
}