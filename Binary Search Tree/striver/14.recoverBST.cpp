#include<iostream>
using namespace std;
void solve(TreeNode* curr, TreeNode* &prev, TreeNode* &a, TreeNode* &b, int &cnt){
    if(curr == NULL)    return;

    solve(curr->left, prev, a, b, cnt);

    if(prev != NULL && (curr->val < prev->val)){
        //means this is a violated node 
        if(cnt == 0){
            //we are getting the first one 
            a = curr;
            b = prev;
            cnt++;
        }
        else{
            //we are getting the second one 
            a = curr;
        }
    }

    prev = curr;

    solve(curr->right, prev, a, b, cnt);
    
}
void recoverTree(TreeNode* root) {
    TreeNode* a;
    TreeNode* b;
    TreeNode* prev = NULL;
    int cnt = 0;
    solve(root, prev, a, b, cnt);
    cout<<a->val<<" "<<b->val<<endl;
    swap(a->val,b->val);
}
int main()
{
    return 0;
}