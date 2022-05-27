/*
             8
          /     \  
        10        3
      /    \        \
    1       6        14
          /   \       /
        9       7    13

Right view of the above tree : 8,3,14,13
Approach 2 : Traverse in root, right, left fashion, and maintain a maxlevel vairable to check if this level's value has been printed 
            or not. Print the value at each level only once and since, right comes first here, it will be right view
        
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

//level will store the current level
//maxLevel will store the max depth encountered till now
void rightView(node* root, int level, int &maxLevel){
    if(root == NULL){
        return;
    }
    //root, right, left
    
    //root
    if(level > maxLevel){
        //this means we have discovered a new level
        cout<<root->data<<" ";
        maxLevel = level;
    }
    //right 
    rightView(root->right,level+1,maxLevel);
    //left
    rightView(root->left,level+1,maxLevel);
}
int main(){
    node* root = buildTree();
    bfs(root);
    int maxLevel = -1;
    rightView(root,0,maxLevel);
    cout<<endl;
    return 0;
}