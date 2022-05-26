//given the preorder and inorder traversal of a tree X, build this tree X.
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
node* createTreeFromTrav(int*in,int*pre,int s,int e){
    static int i = 0; // this variable is initialized only once, its value will not be set to zero in every function call
    if(s>e){
        return NULL;
    }
    //rec case
    node* root = new node(pre[i]);
    int idx = -1;
    for(int j = s; s<=e; j++){
        if(in[j]==pre[i]){
            idx = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTrav(in,pre,s,idx-1);
    root->right = createTreeFromTrav(in,pre,idx+1,e);
    return root;
}
int main()
{   
    int in[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int n = sizeof(in)/sizeof(int);
    node* root = createTreeFromTrav(in,pre,0,n-1);
    bfs(root);
}