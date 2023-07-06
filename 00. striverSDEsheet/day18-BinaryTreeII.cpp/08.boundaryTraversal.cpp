#include<iostream>
using namespace std;
bool isLeaf(Node* root){
    if(root->left == NULL && root->right == NULL)   return true;
    else return false;
}
void takeLeftBoundary(Node* root, vector<int> &ans){
    auto node = root->left;
    while(node!=NULL){
        if(!isLeaf(node))   ans.push_back(node->data);
        if(node->left != NULL)  node = node->left;
        else    node = node->right;
    }
}
void takeRightBoundary(Node* root, vector<int> &ans){
    auto node = root->right;
    vector<int> temp;
    while(node!=NULL){
        if(!isLeaf(node))   temp.push_back(node->data);
        if(node->right != NULL)  node = node->right;
        else    node = node->left;
    }
    for(int i = temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }
}
void takeLeafNodes(Node* root, vector<int> &ans){
    if(root == NULL)    return;
    //root 
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    //left 
    takeLeafNodes(root->left, ans);
    //right
    takeLeafNodes(root->right, ans);
}
vector <int> boundary(Node *root)
{
    vector<int> ans;
    if(root == NULL)    return ans;

    if(!isLeaf(root))   ans.push_back(root->data);

    takeLeftBoundary(root, ans);
    takeLeafNodes(root, ans);
    takeRightBoundary(root, ans);
    return ans;
}
int main()
{
    return 0;
}