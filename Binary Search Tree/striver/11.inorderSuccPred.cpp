#include<iostream>
using namespace std;
/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findSuccessor(Node* root, Node* &suc, int key){
    Node* node = root;
    while(node != NULL){
        if(key >= node->key){
            node = node->right;
        }
        else{
            suc = node;
            node = node->left;
        }
    }
}
void findPredessor(Node* root, Node* &pre, int key){
    Node* node = root;
    while(node != NULL){
        if(key > node->key){
            pre = node;
            node = node->right;
        }
        else{
            node = node->left;
        }
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = suc = NULL;
    findSuccessor(root, suc, key);
    findPredessor(root, pre, key);
}
int main()
{
    return 0;
}