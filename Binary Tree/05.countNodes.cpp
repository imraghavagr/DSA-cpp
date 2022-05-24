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
int countNodes(node* root){
    //base case
    if(root == NULL)    return 0;
    //rec case
    int ls = countNodes(root->left);
    int rs = countNodes(root->right);
    return ls+rs+1;
    //return countNodes(root->left)+countNodes(root->right)+1
}
int main()
{   
    node* root = buildTree();
    printPreOrder(root);
    cout<<endl;
    cout<<countNodes(root)<<endl;
    return 0;
}