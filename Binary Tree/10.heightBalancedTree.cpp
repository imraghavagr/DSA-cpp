//waf to check if a given tree is a height balanced tree or not
/*
Height balanced binary tree is a special kind of tree where the difference between the heights of
the left and right subtree is less than or equal to 1 at every node of the tree.

Eg. of a height balanced tree
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
    //otherwise input root node and rec input left and right st
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
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
pair<int,bool> heightBalance(node* root){
    pair<int,bool> p;
    if(root == NULL){
        //height = 0, balanced = true
        p.first = 0;
        p.second = true;
        return p;
    }
    //else do a bottom up approach [left, right, root]
    pair<int,bool> ls = heightBalance(root->left);
    pair<int,bool> rs = heightBalance(root->right);

    //now root
    p.first = max(ls.first,rs.first)+1;
    if(abs(ls.first-rs.first)<= 1 && ls.second && rs.second){
        //balance of a node will depend on all three conditions
        p.second = true;
    }
    else{
        p.second = false;
    }
    return p;

}
int main()
{   
    node* root = buildTree();
    bfs(root);
    pair<int,bool> p = heightBalance(root);
    cout<<p.first<<" "<<p.second<<endl;
}