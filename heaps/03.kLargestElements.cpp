//given an array and an iteger k
//return the largest k elements of the array 
#include<iostream>
using namespace std;
vector<int> kLargest(int arr[], int n, int k) {
    // code here
    priority_queue<int,vector<int>, greater<>> pq;
    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size() > k)   pq.pop();
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main()
{
    return 0;
}