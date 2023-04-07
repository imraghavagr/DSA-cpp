//https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
#include<iostream>
#include<vector>
using namespace std;
vector<int> delR = {-1, 0, 1, 0};
vector<int> delC = {0, 1, 0, -1};
bool isValid(int i, int j, int m, int n){
    if(i>=0 && i<m && j>=0 && j<n)  return true;
    else    return false;
}
void bfs(vector<vector<int>> &visArr, vector<vector<int>> &ans, vector<vector<int>> &mat){
    int m = mat.size();
    int n = mat[0].size();
    queue<pair<pair<int,int>,int>> q;
    //push all the cells with 0 in the queue
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(mat[i][j] == 0){
                q.push({{i,j},0});
                visArr[i][j] = 1;
            }
        }
    }
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int i = it.first.first;
        int j = it.first.second;
        int d = it.second;

        //visit all unvisited neighbours
        for(int k = 0; k<4; k++){
            int newR = i + delR[k];
            int newC = j + delC[k];
            if(isValid(newR, newC, m, n) && !visArr[newR][newC] && mat[newR][newC] == 1){
                q.push({{newR, newC}, d+1});
                visArr[newR][newC] = 1;
                ans[newR][newC] = d+1;
            }
        }
    }
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> visArr(mat.size(), vector<int>(mat[0].size(), 0));
    vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
    bfs(visArr, ans, mat);
    return ans;
}
int main()
{
    return 0;
}