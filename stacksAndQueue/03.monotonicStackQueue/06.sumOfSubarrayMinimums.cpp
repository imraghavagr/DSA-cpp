#include<iostream>
using namespace std;

//Approach 1 : Monotonic Stack + Contribution of each element 
const unsigned int M = 1e9+7; 
vector<int> NSL(vector<int> &arr){
    vector<int> nsl; 
    stack<int> stk; 
    for(int i = 0; i<arr.size(); i++){
        if(stk.empty()){
            nsl.push_back(-1);
        }
        else if(arr[stk.top()] < arr[i]){
            nsl.push_back(stk.top());
        }
        else{
            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                stk.pop();
            }
            if(stk.empty()) nsl.push_back(-1);
            else    nsl.push_back(stk.top());
        }
        stk.push(i);
    }
    return nsl;
}
vector<int> NSR(vector<int> &arr){
    vector<int> nsr(arr.size());
    stack<int> stk; 
    for(int i = arr.size()-1; i>=0; i--){
        if(stk.empty()){
            nsr[i] = -1;
        }
        else if(arr[stk.top()] <= arr[i]){
            nsr[i] = stk.top();
        }
        else{
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                stk.pop();
            }
            if(stk.empty()) nsr[i] = -1;
            else    nsr[i] = stk.top();
        }
        stk.push(i);
    }
    return nsr;
}
int sumSubarrayMins(vector<int>& arr) {
    vector<int> nsl = NSL(arr);
    vector<int> nsr = NSR(arr);
    // for(auto it : nsl)  cout<<it<<" ";
    // cout<<endl;
    // for(auto it : nsr)  cout<<it<<" ";
    // cout<<endl;
    int sum = 0; 
    for(int i = 0; i<arr.size(); i++){
        //we need to find the number of subarrays in which arr[i] will be minimum
        int left = i - nsl[i];
        int right = (nsr[i] == -1 ? arr.size() : nsr[i]) - i;
        // cout<<left<<" "<<right<<endl;
        int numOfSubarrays = left*right;
        sum = (sum + (numOfSubarrays%M * arr[i])%M)%M;
    }
    return sum; 
}

//Approach 1 : OPTIMAL Implementation - calculating NSL and NSR together in one iteration itself using one stack.


//Approach 2: Monotonic Stack + Dynamic Programming


int main()
{
    return 0;
} 