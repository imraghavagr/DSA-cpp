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
int main()
{
    return 0;
}