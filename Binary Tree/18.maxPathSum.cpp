#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
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
    if(d == -1){
        return NULL;
    }
    //else root, left, right 
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
//we can use inbuilt pair function also, but for better understanding, we are making our own Pair class
class Pair{
    public:
        int branchSum;
        int maxSum;
        Pair(){
            branchSum = 0;
            maxSum = 0;
        }
};
//every node will return branch sum and maxsum
Pair maxSumPath(node*root){
    //solved in bottom up approach - post order, i.e. left, right, root
    Pair p;
    if(root == NULL){
        return p;//P.branchSum and P.maxSum both are already initialized to 0 using c'tor
    }

    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    //now root i.e. p
    /*
        p.maxSum = max(opt1,opt2,opt3)
        opt1 = max(a,b,c,d) //again 4 options for opt1
        opt2 = left.maxSum (found using rec) , opt3 = right.maxSum(found using rec)
        and, 
        a = only root, b = root + left branch sum (right branch sum is negative),
        c = root+right branch sum, d = root+both branch sum
        p.branchSum = max(left branch sum , right branch sum, 0)  + root
    */
    int a = root->data;
    int b = root->data + left.branchSum;
    int c = root->data + right.branchSum;
    int d = root->data + left.branchSum + right.branchSum;
    
    int opt1 = max(a,max(b,max(c,d)));

    p.branchSum = max(left.branchSum,max(right.branchSum,0)) + root->data;
    p.maxSum = max(opt1,max(left.maxSum,right.maxSum));

    return p;
}

int main()
{
    //input = 10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1, ans = 42
    node* root = buildTree();
    Pair p = maxSumPath(root);
    cout<<p.maxSum<<endl;
    return 0;
}