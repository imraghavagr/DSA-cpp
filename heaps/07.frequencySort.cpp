#include<iostream>
using namespace std;
// for defining custom priority. 
struct comp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        //for min heap
        if(a.first == b.first)  return a.second<b.second;
        else    return a.first > b.first;
    }
};
vector<int> frequencySort(vector<int>& nums) {
    //sorting in increasing order of frequency..
    vector<int> ans;
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
    map<int,int> mp;
    for(int num : nums){
        mp[num]++;
    }
    for(auto it : mp){
        pq.push({it.second, it.first});
    }
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        for(int i = 0; i<it.first; i++) ans.push_back(it.second);
    }
    return ans;
}
int main()
{
    return 0;
}