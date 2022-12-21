//this is the optimized approach [O(n)] for finding diameter of a given tree
//Bottom Up Approach
#include<iostream>
#include<queue>
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
int replaceSum(node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        //do not change the leaf nodes
        return root->data;
    }
    //rec case
    //in post order(bottom up) apprach
    int ls = replaceSum(root->left);
    int rs = replaceSum(root->right);
    
    //store the original node value before updating it
    int temp = root->data; 
    root->data = ls+rs;
    return temp+root->data;

}
int main()
{   
    node* root = buildTree();
    bfs(root);
    replaceSum(root);
    bfs(root);
    return 0;
}