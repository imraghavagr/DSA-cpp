//given a tree, count the number of nodes present into it
#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* left; 
        node* right;
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
node* buildTree(){
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }
    //otherwise input root node and rec input left and right st
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}
void printPreOrder(node* root){
    if(root == NULL){
        return;
    }
    //otherwise root, left, right
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);   
}
int sumNodes(node* root){
    //base case
    if(root == NULL)    return 0;
    //rec case
    int ls = sumNodes(root->left);
    int rs = sumNodes(root->right);
    return ls+rs+root->data;
    //return sumNodes(root->left)+sumNodes(root->right)+1
}
int main()
{   
    node* root = buildTree();
    printPreOrder(root);
    cout<<endl;
    cout<<sumNodes(root)<<endl;
    return 0;
}