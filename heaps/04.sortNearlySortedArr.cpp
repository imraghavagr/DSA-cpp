//https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
#include<iostream>
using namespace std;
//Function to return the sorted array.
vector <int> nearlySorted(int arr[], int num, int K){
    vector<int> ans;
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0; i<num; i++){
        pq.push(arr[i]);
        if(pq.size() > K){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
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