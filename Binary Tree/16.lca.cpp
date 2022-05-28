/*
LCA- Lowest common ancestor
Q. Given two nodes A and B, return the lca(a,b)
Important Property: If a node X has to be the lca(a,b), then both a and b must be present in the subtrees
of X and that too in the opposite direction
             
Eg. A = 1, B = 7, lca(A,B) = 10
             8
          /     \  
        10        3
      /    \        \
    1       6        14
          /   \       /
        9       7    13
*/
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

node* lca(node* root, int a, int b){
    //done in pre order fation.. root, left,right
    if(root == NULL){
        return NULL; //...eqn(1)
    }
    if(root->data == a || root->data == b){
        //this means that a or b is found at root
        return root; //...eqn(2)
    }
    //what to return if both above condtions fail

    node* leftans = lca(root->left,a,b);
    node* rightans = lca(root->right,a,b);

    if(leftans != NULL and rightans != NULL){
        /*
             X
          A     B
        this means A is found at the ls 
        and B is found in the rs of root-X or vice-versa
        This observation means that root X is the lca
        */
       return root;
    }

    //if NULL is returned from either one sub tree
    if(leftans!=NULL){
        return leftans;
    }
    return rightans;// controll reaches here means leftans = NULL and rightans is not null
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

int main()
{   
    node* root = buildTree();
    bfs(root);
    int a,b;
    cin>>a>>b;
    node* n = lca(root,a,b);
    cout<<n->data<<endl;
    return 0;
}