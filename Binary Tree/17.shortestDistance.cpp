//shortest distance between two nodes of a binary tree
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node*right;
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
    //else root, left, right 
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
node* lca(node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    //root
    if(root->data == a or root->data == b){
        return root;
    }
    //left,right
    node* ls = lca(root->left,a,b);
    node* rs = lca(root->right,a,b);

    if(ls != NULL and rs != NULL){
        return root;
    }
    if(ls!=NULL){
        return ls;
    }
    return rs;
}
int shortestDistance(node* root, int a, int b){

}
int main()
{
    node* root = buildTree();
    int a,b; 
    cin>>a>>b;
    node* n  = lca(root,a,b);
    cout<<n->data<<endl;
    return 0;
}