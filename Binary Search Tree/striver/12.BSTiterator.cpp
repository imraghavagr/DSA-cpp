#include<iostream>
using namespace std;
class BSTIterator {
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
        //push root into the stack and all the elements at the left of it 
        TreeNode* node = root;
        while(node != NULL){
            stk.push(node);
            node = node->left;
        }
    }
    int next() {
        auto it = stk.top();
        stk.pop();
        //check it node it has any right branch .. if yes .. then push all right values of it 
        auto node = it->right;
        while(node != NULL){
            stk.push(node);
            node = node->left;
        }
        return it->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};
int main()
{
    return 0;
}