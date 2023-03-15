//https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall
#include<iostream>
using namespace std;

void shortest_distance(vector<vector<int>>&dist){
    // Code here
    // vector<vector<int>> dist(matrix.begin(), matrix.end());
    //for the nodes which are not reachable .. put inf or 1e9
    
    int n = dist.size();
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(dist[i][j] == -1)    dist[i][j] = 1e9;
        }
    }
    
    //now go from every node to every other node via all nodes 
    for(int via = 0; via<n; via++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                //no need to change if i == via or j == via 
                if(i == via || j == via){
                    //no need to change
                    continue;
                }
                else{
                    //from i to via and from via to j
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
    //again replace 1e9 by -1
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(dist[i][j] == 1e9)   dist[i][j] = -1;
        }
    }
}

int main()
{
    return 0;
}
