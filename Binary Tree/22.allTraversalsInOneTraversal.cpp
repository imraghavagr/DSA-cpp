#include<iostream>
#include<vector>
#include<stack>
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
    if(root == NULL)    return;
    //root, left, right 
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void printInOrder(node* root){
    if(root == NULL)    return;
    //left, root, right
    printPreOrder(root->left);
    cout<<root->data<<" ";
    printPreOrder(root->right);
}
void printPostOrder(node* root){
    if(root == NULL)    return;
    //left, right, root
    printPreOrder(root->left);
    printPreOrder(root->right);
    cout<<root->data<<" ";
}
void printAllTraversals(node* root){
    stack<pair<node*,int>> stk;
    stk.push({root, 1});
    //pre order - root, left, right
    //in order - left, root, right
    //post order - left, right, root
    vector<int> preorder, inorder, postorder;
    while(!stk.empty()){
        auto node = stk.top();
        stk.pop();
        if(node.second == 1){
            preorder.push_back((node.first)->data);
            stk.push({node.first, node.second+1});
            if((node.first)->left != NULL){
                stk.push({(node.first)->left, 1});
            }
        }
        else if(node.second == 2){
            inorder.push_back((node.first)->data);
            stk.push({node.first, node.second + 1});
            if((node.first)->right != NULL){
                stk.push({(node.first)->right, 1});
            }
        }
        else if(node.second == 3){
            postorder.push_back((node.first)->data);
        }
    }
    for(int x : preorder)   cout<<x<<" ";
    cout<<endl;
    for(int x : inorder)   cout<<x<<" ";
    cout<<endl;
    for(int x : postorder)   cout<<x<<" ";
    cout<<endl;
}

int main()
{
    node* root = buildTree();
    printPreOrder(root);
    cout<<endl;
    printInOrder(root);
    cout<<endl;
    printPostOrder(root);
    cout<<endl;
    printAllTraversals(root);
    return 0;
}