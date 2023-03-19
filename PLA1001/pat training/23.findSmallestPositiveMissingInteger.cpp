#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int solve(vector<int> &nums, int n){
    priority_queue<int,vector<int>, greater<>> pq;
    int cnt = 0;
    for(int i : nums){
        if(i>0)
            pq.push(i);
        else
            cnt++;
    }
    if(pq.size()==0)    return 1;

    //now we have n-cnt number of elements in our pq 
    for(int i = 1; i <= n-cnt; i++){
        int x = pq.top();
        pq.pop();
        if(x != i){
            return i;
        }
    }
    return n;
}
int main()
{   
    int n;
    cin>>n;
    vector<int> nums(n,0);
    int x;
    for(int i = 0; i<n; i++){
        cin>>x;
        nums.push_back(x);
    }
    cout<<solve(nums, n)<<endl;    
    return 0;
}