#include<iostream>
using namespace std;
void solve(Node* root, int x, int &floor){
    if(root == NULL)    return;
    if(root->data == x){
        floor = root->data;
        return;
    }
    else if(root->data > x){
        solve(root->left, x, floor);
    }
    else{
        floor = root->data;
        solve(root->right, x, floor);
    }
}
int floor(Node* root, int x) {
    // Code here
    if(root == NULL)    return -1;
    int floor = -1;
    solve(root, x, floor);
    return floor;
}
//iterative soln
int floor(Node* root, int x) {
    if(root == NULL)    return -1; 
    int ans = -1; 
    Node* curr = root; 
    while(curr != NULL){
        if(curr->data == x){
            return x;
        }
        else if(curr->data < x){
            //this can be a possible ans 
            ans = curr->data; 
            //search for larger ans 
            curr = curr->right;
        }
        else{
            curr = curr->left; 
        }
    }
    return ans; 
}
int main()
{
    return 0;
}