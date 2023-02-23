//https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule
#include<iostream>
using namespace std;
vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
{
    // Code here
    vector<int> adj[N];
    for(auto it : prerequisites){
        adj[it[1]].push_back(it[0]);
    }
    
    //apply topo sort 
    vector<int> indegree(N, 0);
    for(int i = 0; i<N; i++){
        for(int x : adj[i]){
            indegree[x] += 1;
        }
    }
    queue<int> q;
    vector<int> ans;
    //now add all the nodes with indegree = 0 into the queue
    for(int i = 0; i<N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int n = q.front();
        ans.push_back(n);
        q.pop();
        for(int x : adj[n]){
            indegree[x] -= 1;
            if(indegree[x] ==0){
                q.push(x);
            }
        }
    }
    if(ans.size() == N){
        //no cycle present - means it is possible 
        return ans;
    }
    else{
        return {};
    }
}
int main()
{
    return 0;
}