//https://www.interviewbit.com/problems/repeat-and-missing-number-array/
#include<iostream>
#include<vector>
using namespace std;

//Cyclic sort concept
vector<int> solve(vector<int> &nums){
    int i = 0;
    while(i<nums.size()){
        int ci = nums[i] - 1;
        if(ci != i && nums[ci] != nums[i]){
            swap(nums[ci],nums[i]);
        }
        else{
            i++;
        }
    }
    vector<int> ans;
    for(int i = 0; i<nums.size(); i++){
        int ci = nums[i] - 1;
        if(i != ci){
            ans.push_back(nums[i]);
            ans.push_back(i+1);
            break;
        }
    }
    return ans;
}
//Optimal Approach -> Maths based approach 
vector<int> Solution::repeatedNumber(const vector<int> &arr) {
        long long n = arr.size();
        long long int S = (n*(n+1))/2;
        long long int P = (n*(n + 1)*(2*n + 1))/6;
        for(int i = 0; i<n; i++){
            S -= (long long)arr[i];
            P -= ((long long)arr[i]*(long long)arr[i]);
        }
        
        long long missingNum = ((S + (P/S))/2);
        long long remainingNum = missingNum - S;
        return {remainingNum, missingNum};
}
// bitmasking approach => O(n) time, O(1) space
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int xorResult = 0; 
    int n = A.size();
    for(int i = 1; i<=n; i++)   xorResult = xorResult ^ i;
    for(int num : A)    xorResult = xorResult ^ num;
    
    //now we need to find the ith position from right in xorResult, where we have a set bit 
    int temp = xorResult; 
    int setBitIdx = 0; 
    while(temp > 0){
        if(temp & 1){
            //we have set bit at the last 
            break;
        }
        setBitIdx++; 
        temp = (temp>>1);
    }    
    //now we will check what numbers have a set bit and index setBitIdx among all the numbers 
    int mask = (1<<setBitIdx);
    int x = 0; 
    for(int i = 1; i<=n ;i++){
        if((i&mask) != 0)  x = x ^ i; 
    }
    for(int num : A){
        if((num&mask) != 0)   x = x ^ num; 
    }
    int y = xorResult ^ x; 
    //now either of x or y will be repearing or missing 
    int cnt = 0; 
    for(int num : A){
        if(num == x)    cnt++;
    }
    //if cnt = 2, x is our repeating number or else x will be the missing number 
    if(cnt == 2){
        //x is repeating, y is missing 
        return {x,y};
    }
    else{
        return {y,x};
    }
}

int main()
{   
    vector<int> nums = {3,1,2,5,4,6,7,5};
    vector<int> ans = solve(nums);
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}