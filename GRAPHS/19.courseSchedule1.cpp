//https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks
#include<iostream>
using namespace std;
bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
    // Code here
    vector<int> adj[N];
    for(int i = 0; i<prerequisites.size(); i++){
        adj[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    
    //apply topo sort 
    vector<int> indegree(N, 0);
    for(int i = 0; i<N; i++){
        for(int x : adj[i]){
            indegree[x] += 1;
        }
    }
    queue<int> q;
    int cnt = 0;
    //now add all the nodes with indegree = 0 into the queue
    for(int i = 0; i<N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int n = q.front();
        cnt++;
        q.pop();
        for(int x : adj[n]){
            indegree[x] -= 1;
            if(indegree[x] ==0){
                q.push(x);
            }
        }
    }
    if(cnt == N){
        //no cycle present - means it is possible 
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    return 0;
}