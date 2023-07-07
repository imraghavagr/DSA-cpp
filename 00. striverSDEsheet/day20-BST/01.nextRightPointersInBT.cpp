#include<iostream>
using namespace std;
//Approach1 -> using level order traversal -> O(n) time, O(n) space
Node* connect(Node* root) {
    if(root == NULL)    return NULL; 
    queue<Node*> q; 
    q.push(root);
    while(!q.empty()){
        int sz = q.size(); 
        for(int i = 0; i<sz; i++){
            auto node = q.front();  q.pop();
            if(i < sz-1){
                node->next = q.front();
            }
            if(node->left != NULL)  q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
    }
    return root; 
}

//Approach 2-> use the next pointers of prev level 
//O(n) time, O(1) space 
Node* connect(Node* root) {
    if(root == NULL)    return root; 

    Node* leftMostNode = root; 
    while(leftMostNode->left != NULL){
        //now being at current level, we will build up the connections for the child
        Node* node = leftMostNode;
        while(node != NULL){
            //we need to do two connections 
            node->left->next = node->right; 
            if(node->next)
                node->right->next = node->next->left;
            node = node->next; 
        }
        leftMostNode = leftMostNode->left; 
    }
    return root; 
}
int main()
{
    return 0;
}