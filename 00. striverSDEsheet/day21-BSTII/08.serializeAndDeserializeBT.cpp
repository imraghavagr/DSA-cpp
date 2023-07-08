#include<iostream>
using namespace std;
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == NULL)    return "";
    string s = "";
    queue<TreeNode*> q; 
    q.push(root);
    while(!q.empty()){
        auto it = q.front();    q.pop(); 
        if(it == NULL){
            s += "#,";
        }
        else{
            s += to_string(it->val);
            s += ",";
            q.push(it->left);
            q.push(it->right);
        }
    }
    return s; 
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.length() == 0)  return NULL; 
    queue<TreeNode*> q; 
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    q.push(root);
    while(!q.empty()){
        auto node = q.front();  q.pop(); 
        //now, the next two values in the string are node's left and right child 
        getline(s, str, ',');
        if(str == "#")  node->left = NULL;
        else{
            node->left = new TreeNode(stoi(str));
            q.push(node->left);
        }
        getline(s, str, ',');
        if(str == "#")  node->right = NULL; 
        else{
            node->right = new TreeNode(stoi(str));
            q.push(node->right);
        }
    }
    return root; 
}
int main()
{
    return 0;
}