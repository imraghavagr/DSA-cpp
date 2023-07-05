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
//iterative soln - O(h) time, O(1) space 
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    //iterative soln 
    Node* curr = root; 
    int ans = -1;
    while(curr != NULL){
        if(input == curr->data){
            return input;
        }
        else if(curr->data > input){
            //this is a possible ans 
            ans = curr->data; 
            //search for smaller ans 
            curr = curr->left; 
        }
        else{
            curr = curr->right; 
        }
    }
    return ans; 
}
int main()
{
    return 0;
}