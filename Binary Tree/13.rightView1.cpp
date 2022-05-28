/* Solution is incomplete
             8
          /     \  
        10        3
      /    \        \
    1       6        14
          /   \       /
        9       7    13

Right view of the above tree : 8,3,14,13
Approach 1 : Print the last node value in level order traversal of each node
        
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
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void bfs(node* root){
    queue<pair<node*,int>> q;
    if(root == NULL){
        return;
    }
    static int level = 0;
    q.push({root,level++});
    q.push({NULL,-1});
    while(!q.empty()){
        pair<node*,int> f = q.front();
        if(f.first == NULL){
            level++;
            q.pop();
            if(!q.empty()){
                q.push({NULL,-1});
            }
        }
        else{
            if()
            cout<<(f.first)->data<<","<<f.second<<" ";
            q.pop();
            if((f.first)->left != NULL){
                q.push({(f.first)->left,level});
            }
            if((f.first)->right != NULL){
                q.push({(f.first)->right,level});
            }
        }
    }
}
int main(){
    node* root = buildTree();
    bfs(root);
    return 0;
}