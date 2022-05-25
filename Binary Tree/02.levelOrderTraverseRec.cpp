//O(n^2) soln for level order traversal
    //O(n) for finding height of tree + O(n^2) for printing each level
    //o(n+n^2) = O(n^2)
//Better approach - using queue in O(n) [BFS]
#include<iostream>
#include<algorithm>
using namespace std;
/*
Input for following preorder build: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

             8
          /     \  
        10        3
      /    \        \
    1       6        14
          /   \       /
        9       7    13

Steps:
    1.Find height of the tree.
    2.WAF to print data of a given level.
    3.Print data in each level of a tree one at a time starting from level 1 to tree height.
*/
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
void printInOrder(node *root){
    if(root == NULL){
        return;
    }
    //otherwise root left right
    cout<<root->data<<' ';
    printInOrder(root->left);
    printInOrder(root->right);
}
int height(node* root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls,rs)+1;
}
void printKthLevel(node*root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout<<root->data<<' ';
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;
}
void printLevelOrder(node* root){
    int h = height(root);
    for(int i =1; i<=h; i++){
        printKthLevel(root,i);
    }
    cout<<endl;
}
int main()
{
    node* root = buildTree();
    printInOrder(root);
    cout<<endl;
    cout<<height(root)<<endl;
    printLevelOrder(root);
    return 0;
}