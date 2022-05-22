#include<iostream>
#include<queue>

using namespace std;
class node{
    public:
        int data;
        node*left;
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
    if( d == -1)    return NULL;
    node*root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void bfs(node* root){
    queue<node*> q; // the queue will contain the addresses of the nodes of the tree

    if(root == NULL) return;

    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        cout<<f->data<<" ";
        q.pop();
        if(f->left != NULL){
            q.push(f->left);
        }
        if(f->right != NULL){
            q.push(f->right);
        }
    }
    cout<<endl;
}

int main()
{   
    node* root = buildTree();
    bfs(root);
    return 0;
}