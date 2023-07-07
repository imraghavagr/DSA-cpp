#include<iostream>
using namespace std;
//Approach 1 => Recursive solution:O(n) time, O(n) space
//             1. do right left root traversal
//             2. For curr node, update curr->right = prev; curr->left = NULL; 
//             3. Update prev = curr;
TreeNode* prev = NULL; 
void solve(TreeNode* root){
    if(root == NULL)    return;

    //right 
    solve(root->right);
    //left
    solve(root->left);
    //root
    //connect the curr node's right to the prev node 
    root->right = prev;
    //connect curr node's left to null 
    root->left = NULL;
    //update prev to curr node 
    prev = root; 
}
void flatten(TreeNode* root) {
    if(root == NULL)    return;
    solve(root);
}

//Iterative method - using stack -> O(n) time, O(n) space
void flatten(TreeNode* root) {
    if(root == NULL)    return;
    stack<TreeNode*> stk; 
    stk.push(root);
    while(!stk.empty()){
        TreeNode* curr = stk.top();     stk.pop(); 
        if(curr -> right){
            stk.push(curr->right);
        }
        if(curr->left){
            stk.push(curr->left);
        }
        //since we have inserted left after right, because of LIFO, the prev nodes left...
        //will be at the stk.top .. and we need to connect that to curr nodes right 
        if(!stk.empty()){
            curr->right = stk.top();
        }
        curr->left = NULL;
    }
}

//Optimal Approach -> O(n) time, O(1) space
//Similar to morris traversal 
void flatten(TreeNode* root) {
    if(root == NULL)    return; 
    TreeNode* curr = root; 
    while(curr != NULL){
        if(curr->left != NULL){
            //first find the rightmost node in the ls of curr node 
            TreeNode* prev = curr->left; 
            while(prev->right != NULL){
                prev = prev->right; 
            }
            //now connect that last node to the curr node's right 
            prev->right = curr->right; 
            //also connect curr's right to curr's left 
            curr->right = curr->left; 
            //also make the current nodes left as null 
            curr->left = NULL; 
        }
        //move curr to curr->right 
        curr = curr->right; 
    }
}
int main()
{
    return 0;
}