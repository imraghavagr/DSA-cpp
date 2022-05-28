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
void printInOrder(node* root){
    if(root==NULL){
        return;
    }
    //left, right, root
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}
//this will take the curent node, data and will return the new node after inserting data into its correct position
node* insertAtBST(node* root, int d){
    //base case
    if(root == NULL){
        return new node(d);
    }
    //rec case
    if(d <= root->data){
        root->left = insertAtBST(root->left,d);
    }
    else{
        root->right=insertAtBST(root->right,d);
    }
    return root; 
}
//this function will take input untill -1 is encountered and will create a bst with all the data entered before -1
node* buildBST(){
    int d;
    cin>>d;
    node* root = NULL;
    while(d!=-1){
        root = insertAtBST(root,d);
        cin>>d;
    }
    return root;
}
int main(){
    node* root = buildBST();
    printInOrder(root); // an in order traversel of BST will always give sorted output
    cout<<endl;
    bfs(root);
    return 0;
}