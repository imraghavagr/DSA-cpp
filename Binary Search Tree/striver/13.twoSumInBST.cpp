#include<iostream>
using namespace std;
int next(stack<TreeNode*> &stk){
    auto it = stk.top();
    stk.pop();
    //check if there exists any right child 
    if(it->right != NULL) goToLeftBranch(it->right, stk);
    return it->val;
}
int before(stack<TreeNode*> &stk){
    auto it = stk.top();
    stk.pop();
    //check if there exists any right child 
    if(it->left != NULL) goToRightBranch(it->left, stk);
    return it->val;
}
void goToLeftBranch(TreeNode* node, stack<TreeNode*> &stk){
    while(node){
        stk.push(node);
        node = node->left;
    }
}
void goToRightBranch(TreeNode* node, stack<TreeNode*> &stk){
    while(node){
        stk.push(node);
        node = node->right;
    }
}
bool findTarget(TreeNode* root, int k) {

    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;
    
    goToLeftBranch(root, stk1);
    goToRightBranch(root, stk2);

    int left = next(stk1);
    int right = before(stk2);
    while(left < right){
        if(left + right == k){
            return true;
        }
        else if(left+right > k){
            right = before(stk2);
        }
        else{
            left = next(stk1);
        }
    }
    return false;
}
int main()
{
    return 0;
}