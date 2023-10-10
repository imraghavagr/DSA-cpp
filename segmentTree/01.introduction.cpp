//Tree based implementation
#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data, startInterval, endInterval; 
    Node*left, *right; 
    Node(int startInterval, int endInterval){
        this->startInterval = startInterval; 
        this->endInterval = endInterval;
        left = NULL; 
        right = NULL; 
    }
};

//O(N) to make the tree 
Node* constructTree(vector<int> &arr, int si, int ei){
    if(si == ei){
        Node* leafNode = new Node(si, ei); 
        leafNode->data = arr[si]; 
        return leafNode; 
    }

    //post-order left, right, root 
    Node* newNode = new Node(si, ei); 

    int mid = (si+ei)/2;
    newNode->left =  constructTree(arr, si, mid); 
    newNode->right = constructTree(arr, mid+1, ei); 

    newNode->data = newNode->left->data + newNode->right->data;  

    return newNode;
}

//finding query - O(LogN)
int findSum(Node* root, int si, int ei){
    if(root == NULL)    return 0; 

    //case 1: query is completely inside the node 
    if(root->startInterval >= si && root->endInterval <= ei)    return root->data; 

    //case 2: Node interval is completely outside the query interval 
    else if(si > root->endInterval || ei < root->startInterval)  return 0; 

    //case 3: Overlapping 
    else{
        int leftSum = findSum(root->left, si, ei); 
        int rightSum = findSum(root->right, si, ei); 
        return leftSum + rightSum;
    }
}

//update 
int updateValue(Node* node, int idx, int val){ 

    if(idx >= node->startInterval && idx <= node->endInterval){
        if(idx > node->startInterval && idx < node->endInterval){
            node->data = val; 
            return val; 
        }
        else{
            node->data = updateValue(node->left, idx, val) + updateValue(node->right, idx, val);
            return node->data; 
        }
    }
    else    return node->data;
}
void postOrder(Node* root){
    if(root == NULL)    return; 
    postOrder(root->left); 
    postOrder(root->right); 
    cout<<root->data<<" ";
}
int main()
{   
    vector<int> arr = {3, 8, 7, 6, -2, -8, 4, 9}; 
    Node* rootNode = constructTree(arr, 0, arr.size()-1); 

    // postOrder(rootNode);
    // cout<<endl;

    cout<<rootNode->data<<endl;

    cout<<findSum(rootNode, 2, 6)<<endl;

    updateValue(rootNode, 3, 14);

    cout<<findSum(rootNode, 2, 6)<<endl;

    return 0;
}