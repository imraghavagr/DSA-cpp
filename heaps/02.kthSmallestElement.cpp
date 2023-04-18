//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
#include<iostream>
using namespace std;
//l and r are the starting and ending index of the array 
int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;
    for(int i = l; i<=r; i++){
        pq.push(arr[i]);
        if(pq.size() > k)   pq.pop();
    }
    return pq.top();
}
int main()
{
    return 0;
}