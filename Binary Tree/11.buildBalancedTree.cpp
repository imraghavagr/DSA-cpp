//Given an array, build a height balanced binary tree using it
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
node* buildBalancedTree(int* arr, int s, int e){
    if(s>e) return NULL;

    //rec case
    int mid = (s+e)/2;
    
    //input root
    node* root = new node(arr[mid]);
    //rec input ls and rs
    root->left = buildBalancedTree(arr,s,mid-1);
    root->right = buildBalancedTree(arr,mid+1,e);
    return root;
}
int main()
{   
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);

    node* root = buildBalancedTree(arr,0,n-1);
    bfs(root);
}