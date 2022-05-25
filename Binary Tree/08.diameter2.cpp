//this is the optimized approach [O(n)] for finding diameter of a given tree
//Bottom Up Approach
#include<iostream>
#include<algorithm>

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
int height(node* root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs)+1;
}
pair<int,int> fastDiameter(node* root){
    pair<int,int> p; // to store height, diameter that will be returned by each node
    if(root == NULL){
        //this means return h = d = 0
        p.first = 0;
        p.second = 0;
        return p;
    }
    //rec case for bottom up (i.e. post order- left, right, root)
    pair<int,int> ls = fastDiameter(root->left); //left
    pair<int,int> rs = fastDiameter(root->right); //right
    //now for root
    p.first = max(ls.first,rs.first)+1; // max(h1,h2)+1; h1 and h2 are heights of left and right st
    p.second = max((ls.first+rs.first),max(ls.second,rs.second));// d = max[(h1+h2),d1,d2]
    return p;
}
int main()
{   
    node* root = buildTree();
    pair<int,int> p = fastDiameter(root);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}