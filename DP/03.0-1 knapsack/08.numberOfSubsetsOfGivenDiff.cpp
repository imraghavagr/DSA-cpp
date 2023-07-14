/*
given an array and a target difference..
count the number of 2 partitions of arr s.t. the difference between the sum of those two partitions is equal to the given difference.
eg. arr = {1,1,2,3}, difference = 1
o/p = 3
Explaination:
1st way: s1 = {1,3} s2 = {1,2}
2nd way: s1 = {1,3} s2 = {1,2} [yha doosra waala 1 liya hai]
3rd way: s1 = {1,1,2} s2 = {3} 
In all above ways, sum(s1)-sum(s2) = 1, therefore o/p = 3
*/
#include<iostream>
using namespace std;
int perfectSum(vector<int> &arr, int n, int sum)
{
    vector<int> prev(sum+1, 0), curr(sum+1, 0);
    prev[0] = 1;
    
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=sum; j++){
            if(arr[i-1] <= j){
                curr[j] = ((prev[j-arr[i-1]])%m + (prev[j])%m)%m;
            }
            else{
                curr[j] = prev[j]%m;
            }
        }
        prev = curr; 
    }
    return prev[sum];
}
int countPartitions(int n, int d, vector<int>& arr) {
    long long totalSum = 0; 
    for(int &num : arr) totalSum += num; 
    if(d > totalSum || (totalSum - d) % 2 != 0) return 0; 
    // cout<<totalSum<<endl;
    int reqSum = (totalSum - d)/2;
    // cout<<reqSum<<endl;
    return perfectSum(arr, n, reqSum);
}
int main()
{
    int arr[] = {1,1,2,3};
    int n = sizeof(arr)/sizeof(int);
    int diff = 1;
    cout<<countSubsetDiff(arr,n,diff)<<endl;
    return 0;
}