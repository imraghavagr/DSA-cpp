#include<iostream>
using namespace std;
void bfs(Node* root, map<int,int> &mp){
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        auto node = it.first;
        int verticalLineNum = it.second;
        mp[verticalLineNum] = node->data;
        if(node->left) q.push({node->left, verticalLineNum-1});
        if(node->right) q.push({node->right, verticalLineNum+1});
    }
}
vector <int> bottomView(Node *root) {
    // Your Code Here
    vector<int> ans;
    if(root == NULL)    return ans;
    map<int,int> mp;
    bfs(root, mp);
    for(auto it : mp)   ans.push_back(it.second);
    return ans;
}
int main()
{
    return 0;
}