//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include<iostream>
using namespace std;
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int,int>> v;
    for(int i  = 0; i<n; i++){
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(),  v.end()); 
    int cnt  = 0;
    int currentTime = 0;
    for(auto it : v){
        if(it.second > currentTime){
            cnt++;
            currentTime = it.first;
        }
    }
    return cnt;
}
int main()
{
    return 0;
}