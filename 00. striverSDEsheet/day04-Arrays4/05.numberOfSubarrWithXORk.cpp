#include<iostream>
using namespace std;
//O(N) time O(N) space : assuming unordered_map have no collisions and takes O(1) time 
int subarraysXor(vector<int> &arr, int k)
{
    int cnt = 0;
    int xorValue = 0;
    unordered_map<int,int> mp;
    mp[0] = 1;
    for(int i = 0; i<arr.size(); i++){
        xorValue = xorValue ^ arr[i];
        int x = xorValue ^ k;
        cnt += mp[x];
        mp[xorValue]++;
    }
    return cnt;
}
int main()
{
    return 0;
}