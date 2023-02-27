//https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze
#include<iostream>
using namespace std;
//apply Dijkstra's Algorithm
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                    pair<int, int> destination) {
    
    //if source and destination are already same
    if(source.first == destination.first && source.second == destination.second)    return 0;
    
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> distance(m, vector<int>(n,1e9));
    //we can use a queue instead of a priority queueu here as edge weight is alwasy 1 
    queue<pair<int,pair<int,int>>> q;
    
    distance[source.first][source.second] = 0;
    q.push({0,{source.first, source.second}});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int i = it.second.first;
        int j = it.second.second;
        int d = it.first;
        
        //move in all 4 directions 
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        for(int k = 0; k<4; k++){
            int newR = i + deltaRow[k];
            int newC = j + deltaCol[k];
            
            if(newR >= 0 && newR < m && newC >=0 && newC<n
                && grid[newR][newC] == 1
                && d+1 < distance[newR][newC]){
                    
                if(newR == destination.first && newC == destination.second) return 1+d;
                
                q.push({d+1, {newR, newC}});
                distance[newR][newC] = d+1;
            }
        }
    }
    return -1;
}
int main()
{
    return 0;
}