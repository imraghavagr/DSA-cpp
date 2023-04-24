#include<iostream>
using namespace std;
//always connect 2 ropes of min length
long long minCost(long long arr[], long long n) {
    priority_queue<int, vector<int>, greater<>> pq;
    for(long long i = 0; i<n; i++){
        pq.push(arr[i]);
    }
    long long cost = 0;
    while(pq.size() >= 2){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        cost += (a+b);
        pq.push(a+b);
    }
    return cost;
}
int main()
{
    return 0;
}