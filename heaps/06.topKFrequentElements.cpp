//https://leetcode.com/problems/top-k-frequent-elements/description/
#include<iostream>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(int num : nums){
        mp[num]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for(auto it : mp){
        pq.push({it.second, it.first});
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