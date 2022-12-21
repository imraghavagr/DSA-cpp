/*
Binary Tree - Heirarchichal non linear ds.
Each parent can have atmost 2 children (0,1,2)
 
Example:
Input for following preorder build: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

             8
          /     \  
        10        3
      /    \        \
    1       6        14
          /   \       /
        9       7    13
        
Output: 
a) Pre-order [Root Left Right]  : 8 10 1 6 9 78 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 3 14 13 
b) In-order   [Left Root Right] : 1 10 9 6 7 8 3 13 14
c) Post-order [Left Right Root] : 1 9 7 6 10 13 14 3 8
d) Level-order [level wise]     : 8 10 3 1 6 14 9 7 13

Binary Tree can be build and traversed in different ways.
Different traversal methods - Pre-Order, In-Order, Post-Order, Level Order
*/

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
    //in-order build
    //build the root node
    //recursively build the left and right subtree
    //input = 3 -1 -1 means, there is root node 3, and left side is null, and right side is null

    int d;
    cin>>d;

    //base case
    if(d==-1){
        //-1 in the input means return
        return NULL;
    }
    //build the root node
    node* root = new node(d);

    //rec build the left and right subtree
    root->left = buildTree();
    root->right = buildTree();

    return root;
}
void printPreOrder(node* root){
    //Root -> Left -> Right

    if(root == NULL){
        return;
    }
    //otherwise, print root first followed by left and then right
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void printInOrder(node* root){
    //left, root, right
    if(root == NULL){
        return;
    }

    //else left root right
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);

}
void printPostOrder(node* root){
    //left, right, root
    if(root == NULL){
        return;
    }

    //else left right root
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";  
}
int main()
{
    node* root = buildTree();
    
    cout<<"Pre-Order Traversal: ";
    printPreOrder(root);
    cout<<endl;

    cout<<"In-Order Traversal: ";
    printInOrder(root);
    cout<<endl;
    
    cout<<"Post-Order Traversal: ";
    printPostOrder(root);
    cout<<endl;
    return 0;
}