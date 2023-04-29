#include<iostream>
using namespace std;
void solve(Node* root, int &ceil, int input){
    if(root == NULL)    return;
    if(root->data == input){
        ceil = root->data;
        return;
    }
    else if(root->data > input){
        ceil = root->data;
        solve(root->left, ceil, input);
    }
    else    solve(root->right, ceil, input);
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ceil = -1;
    solve(root, ceil, input);
    return ceil;
}
int main()
{
    return 0;
}