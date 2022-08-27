#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int ms=0,cs=0;
    //for case when all elements are negative
    int maxElem = INT_MIN;
    for(int i = 0; i<nums.size(); i++){
        cs += nums[i];
        if(cs<0)    cs = 0;
        ms = max(ms,cs);
        if(maxElem < nums[i]){
            maxElem = nums[i];
        }
    }
    if(maxElem<0){
        return maxElem;
    }
    else{
        return ms;
    }
}
int main()
{
    vector<int> v = {-4,1,3,-2,6,2,-1,-7};
    cout<<maxSubArray(v)<<endl;
    vector<int> x = {-1,-2,-3,-4};
    cout<<maxSubArray(x)<<endl;
    return 0;
}