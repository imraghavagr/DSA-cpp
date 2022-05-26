//waf to check if a given tree is a height balanced tree or not
/*
Height balanced binary tree is a special kind of tree where the difference between the heights of
the left and right subtree is less than or equal to 1 at every node of the tree.

Eg. of a height balanced tree
             8
          /     \  
        10        3
      /    \        \
    1       6        14
          /   \       /
        9       7    13   

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
void bfs(node* root){
    queue<node*> q; // the queue will contain the addresses of the nodes of the tree

    if(root == NULL) return;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty())    q.push(NULL);
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left != NULL){
                q.push(f->left);
            }
            if(f->right != NULL){
                q.push(f->right);
            }
        }
    }
    
}

int main()
{   
    
}