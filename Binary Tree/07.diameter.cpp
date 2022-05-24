//given a tree, return the diameter of the tree
//diameter of a tree is the largest distance between any two nodes of the tree.
#include<iostream>
#include<algorithm>
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
int height(node* root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs)+1;
}
int diameter(node* root){
    if(root == NULL){
        return 0;
    }
    //case1: dia passes through the root
    int h1 = height(root->left);
    int h2 = height(root->right);
    int option1 = h1+h2; 

    //case2: diameter lies in the left subtree
    int option2 = diameter(root->left); 
    //this will return the largest distance bw two nodes but in the ls

    //case3: diameter lies in the right subtree
    int option3 = diameter(root->right);
    //this will return the largest distance bw two nodes but in the rs

    //return max of all options
    return max(option1,max(option2,option3));
}
int main()
{   
    node* root = buildTree();
    printPreOrder(root);
    cout<<endl;
    cout<<diameter(root)<<endl;
    return 0;
}