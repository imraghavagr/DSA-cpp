#include<iostream>
using namespace std;
void bfs(Node* root, map<int,int> &mp){
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        auto node = it.first;
        auto vertical = it.second;
        if(mp.find(vertical) == mp.end())   mp[vertical] = node->data;
        if(node->left) q.push({node->left, vertical-1});
        if(node->right) q.push({node->right, vertical+1});
    }
}
vector<int> topView(Node *root)
{   
    vector<int> ans;
    if(root == NULL)    return ans;
    map<int, int> mp; // {vertical, value}
    bfs(root, mp);
    for(auto it : mp)   ans.push_back(it.second);
    return ans;
}
int main()
{
    return 0;
}