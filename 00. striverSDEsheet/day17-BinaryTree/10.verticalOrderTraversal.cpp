#include<iostream>
using namespace std;
void bfs(TreeNode* root, map<int, map<int, multiset<int>>> &mp){
    queue<pair<TreeNode*, pair<int,int>>> q; // {node,{vertical,level}}
    q.push({root, {0,0}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int vertical = it.second.first;
        int level = it.second.second;
        //insert into the map
        // mp[vertical] = mp[level].insert(node->val);
        mp[vertical][level].insert(node->val);

        //now insert the left and right children if present 
        if(node->left)  q.push({node->left, {vertical-1, level+1}});
        if(node->right) q.push({node->right, {vertical+1, level+1}});
    }
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL)    return ans;
    map<int, map<int, multiset<int>>> mp;
    bfs(root, mp);
    for(auto it : mp){
        vector<int> temp;
        for(auto it2 : it.second){
            for(auto val : it2.second){
                temp.push_back(val);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    return 0;
}