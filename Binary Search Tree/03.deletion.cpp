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
    queue<node*> q;
    if(root == NULL){
        return;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<root->data<<" ";
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
node* insertAtBST(node* root, int d){
    if(root==NULL){
        return new node(d);
    }
    if(d <= root->data){
        root->left = insertAtBST(root->left,d);
    }
    else{
        root->right = insertAtBST(root->right,d);
    }
    return root;
}
node* buildBST(){
    int d;
    cin>>d;
    node*root = NULL;
    while(d!=-1){
        root = insertAtBST(root,d);
        cin>>d;
    }
    return root;
}
int main()
{   
    node* root = buildBST();
    bfs(root);
    return 0;
}