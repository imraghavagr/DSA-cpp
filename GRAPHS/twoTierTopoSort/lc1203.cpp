//https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/
#include<iostream>
using namespace std;
vector<int> topoSort(vector<int> adj[], vector<int> &indegree){
    vector<int> ans; 
    queue<int> q; 
    for(int i = 0; i<indegree.size(); i++){
        if(indegree[i] == 0)    q.push(i);
    }
    while(!q.empty()){
        int node = q.front();   q.pop(); 
        ans.push_back(node);
        for(auto &it : adj[node]){
            indegree[it]--; 
            if(indegree[it] == 0)   q.push(it);
        }
    }
    return ans; 
}
vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    for(int i = 0; i<group.size(); i++){
        if(group[i] == -1){
            group[i] = m++; 
        }
    }
    vector<int> itemAdj[n];
    vector<int> groupAdj[m];
    vector<int> itemIndegree(n, 0);
    vector<int> groupIndegree(m, 0);
    //now lets make two graphs -> item graph and group graph 
    for(int i = 0; i<beforeItems.size(); i++){
        for(auto it : beforeItems[i]){
            int u = it; 
            int v = i; 
            //u->v
            itemAdj[u].push_back(v);
            itemIndegree[v]++;
            //now make group adj 
            int grpU = group[u];
            int grpV = group[v];
            if(grpU != grpV){
                //grpU->grpV 
                groupAdj[grpU].push_back(grpV);
                groupIndegree[grpV]++;
            }
        }
    }
    //now apply toposort on both graphs 
    vector<int> itemTopoSort = topoSort(itemAdj, itemIndegree);
    if(itemTopoSort.size() != n)    return {};
    vector<int> groupTopoSort = topoSort(groupAdj, groupIndegree);
    if(groupTopoSort.size() != m)   return {};
    
    //now lets make the hashmap 
    unordered_map<int,vector<int>> mp; //group, items 
    for(auto it : itemTopoSort){
        //add it to its correct group in mp 
        mp[group[it]].push_back(it);
    }
    vector<int> ans; 
    for(auto it : groupTopoSort){
        for(auto &it2 : mp[it]){
            ans.push_back(it2);
        }
    }
    
    return ans; 
}
int main()
{
    return 0;
}