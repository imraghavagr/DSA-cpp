//https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
#include<iostream>
using namespace std;
int minimumMultiplications(vector<int>& arr, int start, int end) {
    // code here
    //nodes will be in the range 0 to 9999
    vector<int> steps(100000, 1e9);
    queue<pair<int,int>> q;
    q.push({0,start});
    steps[start] = 0;
    int M = 1e5;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int node = it.second;
        int stepsTaken = it.first;
        for(int i = 0; i<arr.size(); i++){
            int adjNode = (arr[i] * node)%M;
            if(adjNode == end)  return stepsTaken+1;
            if(stepsTaken + 1 < steps[adjNode]){
                steps[adjNode] = stepsTaken + 1;
                q.push({stepsTaken+1, adjNode});
            }
        }
    }
    return -1;
}
int main()
{
    return 0;
}