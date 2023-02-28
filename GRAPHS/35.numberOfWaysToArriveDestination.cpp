//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
#include<iostream>
using namespace std;
int countPaths(int n, vector<vector<int>>& roads) {
    const unsigned int M = 1e9 + 7;
    //fist leats create an adj list 
    vector<pair<long long ,long long>> adj[n];
    for(auto it : roads){
        //bidirectional roads
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<long long> distance(n, 1e18);
    vector<long long> ways(n, 0);
    //min heap - {dis, node}
    priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, greater<>> pq;
    
    distance[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        long long dis = it.first;
        long long node = it.second;
        for(auto iter : adj[node]){
            long long adjN = iter.first;
            long long edgeW = iter.second;
            //if a node has already reached with min dis 
            if(dis + edgeW == distance[adjN]){
                //this means we have to increase the number of ways 
                ways[adjN] = (ways[adjN] + ways[node])%M;
            }
            //this is the first time i am arriving with this shorter distance
            else if(dis + edgeW < distance[adjN]){
                distance[adjN] = dis + edgeW;
                pq.push({dis + edgeW, adjN});
                //in order to reach here, i came via node, so will take the same value
                ways[adjN] = ways[node];
            }
        }
    }
    //it is given in the question, that we can always reach the end. 
    return ways[n-1]%M;
}
int main()
{
    return 0;
}