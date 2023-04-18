#include<iostream>
using namespace std;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int,int>> pq;
    //nlog(k) - at max heap size will be k at any given time
    for(int num : arr){
        pq.push({abs(x-num), num});
        if(pq.size() > k)   pq.pop();
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
int main()
{
    return 0;
}