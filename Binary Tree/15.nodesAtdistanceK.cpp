/*
             8
          /     \  
        10        3
      /    \        \
    1       6        14
          /   \       /
        9       7    13

Given a binary tree, a target node and an integer K. 
Find all the nodes which are at a distance of 'k' units from the target node.
For eg- In above tree for target node = 1 and k = 3,
o/p = 9,7,3
*/
#include<iostream>
#include<queue>
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
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void printKthLevel(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;
}
int printAtDistanceK(node* root, node* target, int k){
    if(root == NULL){
        //target is not present
        return -1;
    }
    //while traversing if we reach the target node
    if(root == target){
        printKthLevel(root,k);
        return 0; //means the target node is present at a distance 0 from the root node of this subtree
    }
    //now for the ancestors part
    //DL will be the distance of target node from the root node of left subtree
    int DL = printAtDistanceK(root->left, target,k);
    if(DL != -1){
        //this means the targe node is present in left subtree
        //two cases - print the ancestor itself or we need to go to wite of the current ancestor
        if(DL+1 == k){
            cout<<root->data<<" ";
        }
        else{
            printKthLevel(root->right,k-2-DL);
        }
        return DL+1;
    }
    
    //DR will be the distance of target node from the root node of right subtree
    int DR = printAtDistanceK(root->right, target, k);
    if(DR != -1){
        if(DR + 1 == k){
            //print ancestor itself
            cout<<root->data<<" ";
        }
        else{
            printKthLevel(root->left,k-2-DR);
        }
        return DR+1;
    }
    return -1; // node was not present in either left or right subtree of the given node.
}
int main(){
    node* root = buildTree();
    node* target = root->left->left;
    printAtDistanceK(root,target,3);
    cout<<endl;
    return 0;
}