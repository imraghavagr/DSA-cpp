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
void printPostOrder(node* root){
    //left, right, root
    if(root == NULL){
        return;
    }

    //else left right root
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";  
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
node* createTreeFromTrav(int*in,int*pre,int s,int e){
    static int i = 0; // this variable is initialized only once, its value will not be set to zero in every function call
    //i will keep track of the traversal of pre order array
    if(s>e){
        return NULL;
    }
    //rec case
    node* root = new node(pre[i]); //make root using the element at ith idx of pre order trav array
    //since it is an unsorted array, find the idx of pre[i] in in order array
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
    int in[] = {2,5,6,7,8,9,10,12,15,17};
    int pre[] = {8,6,5,2,7,10,9,15,12,17};
    int n = sizeof(in)/sizeof(int);
    node* root = createTreeFromTrav(in,pre,0,n-1);
    bfs(root);
    printPostOrder(root);
    return 0;
}