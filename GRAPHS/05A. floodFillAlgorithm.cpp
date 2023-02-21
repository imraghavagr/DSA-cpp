#include<iostream>
using namespace std;
//start from the starting pixel i.e. sr, sc 
//perform a bfs/dfs starting form it and for all the pixels having same value as image[sr][sc] and change the color value to the new color value 
void dfs(vector<vector<int>> &image, int i, int j, int nc, 
            vector<vector<int>> &visArr, vector<vector<int>> &ans, int m, int n, int val){
    
    visArr[i][j] = 1;
    
    //visit in al 4 directions 
    //first visit left and right 
    for(int p = -1; p<=1; p++){
        if(j+p>=0 && j+p<n && image[i][j+p] == val && !visArr[i][j+p]){
            ans[i][j+p] = nc;
            dfs(image, i, j+p, nc, visArr, ans, m, n, val);
        }
    }
    //visit up and down 
    for(int p = -1; p<=1; p++){
        if(i+p>=0 && i+p<m && image[i+p][j] == val && !visArr[i+p][j]){
            ans[i+p][j] = nc;
            dfs(image, i+p, j, nc, visArr, ans, m, n, val);
        }
    }
    
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Code here 
    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> visArr(m,vector<int>(n,0));
    vector<vector<int>> ans = image;
    int val = image[sr][sc];
    ans[sr][sc] = newColor;
    dfs(image, sr, sc, newColor, visArr, ans, m, n, val);
    return ans;
}
int main()
{
    return 0;
}