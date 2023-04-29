#include<iostream>
using namespace std;
int solve(Node* root){
    if(root->left == NULL) return root->data;
    solve(root->left);
}
int minValue(Node* root) {
    // Code here
    if(root == NULL)    return -1;
    if(root->left == NULL)  return root->data;
    return solve(root);
}
int main()
{
    return 0;
}