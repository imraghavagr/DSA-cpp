//shortest distance between two nodes of a binary tree
/*
To find shortest distance between nodes- a,b of a given binary tree:
Step 1: Find lca (a,b)
Step 2: Find the distance(d1) of node a from the lca node
Step 3: Find the distance(d2) of node b from the lca node
Step 4: Return d1+d2
*/
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
//finding level of a given node from any other root node which is at given level-l
int findLevel(node* root,int a, int level){
    if(root == NULL){
        return -1; //not found
    }
    //root
    if(root->data == a){
        return level;
    }
    //left
    int ls = findLevel(root->left, a, level+1);
    if(ls!=-1){
        return ls;
    }
    //search on the right subtree if it is not present in the left subtree
    int rs = findLevel(root->right,a,level+1);
    return rs;
}
int shortestDistance(node* root, int a, int b){
    node* lca_node = lca(root,a,b);
    //now find distance of a from the lca_node
    int d1 = findLevel(lca_node,a,0);
    int d2 = findLevel(lca_node,b,0);
    return d1+d2;
}
int main()
{
    node* root = buildTree();
    int a,b; 
    cin>>a>>b;
    cout<<shortestDistance(root,a,b)<<endl;
    return 0;
}