#include<bits/stdc++.h>
vector<int> NSL(vector<int>& arr){
    stack<pair<int,int>> s; //nsl, idx
    vector<int> ans;
    for(int i = 0; i<arr.size(); i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(s.top().first < arr[i]){
            ans.push_back(s.top().second);
        }
        else{
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top().second);
            }

        }
        s.push(make_pair(arr[i],i));
    }
    return ans;
}
vector<int> NSR(vector<int>& arr){
    stack<pair<int,int>> s; //nsl, idx
    vector<int> ans;
    for(int i = arr.size()-1; i>=0; i--){
        if(s.empty()){
            ans.push_back(arr.size());
        }
        else if(s.top().first < arr[i]){
            ans.push_back(s.top().second);
        }
        else{
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(arr.size());
            }
            else{
                ans.push_back(s.top().second);
            }

        }
        s.push(make_pair(arr[i],i));
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    vector<int> nsl = NSL(heights);
    vector<int> nsr = NSR(heights);
    for(int i = 0; i<heights.size(); i++){
        int area = ((nsr[i]-nsl[i])-1)*heights[i];
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    //nxm
    int n = matrix.size();
    int m = matrix[0].size();
    int maxArea = 0;
    vector<int> height(m,0);
    for(int i = 0; i<n; i++){
        //now we will form the height array for each row
        for(int j = 0; j<m; j++){
            if(matrix[i][j] == '0'){
                height[j]=0;
            }
            else{
                height[j]++;
            }
        }   
        //once the height arrayi is formed, find the area under histogram for it
        int area = largestRectangleArea(height);
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int main(){
    
    return 0;
}