#include<iostream>
using namespace std;
void findTarget(Node* root, int target, Node* &targetNode){
    if(root == NULL)    return;
    if(root->data == target){
        targetNode = root;
        return;
    }
    findTarget(root->left, target, targetNode);
    findTarget(root->right, target, targetNode);
}
//we can also find the target nodes address in the following function while finding the parents pointer 

void findParents(Node* root, unordered_map<Node*, Node*> &mp){
    queue<Node*> q;
    q.push(root);
    mp[root] = NULL;
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        if(node->left){
            mp[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            mp[node->right] = node;
            q.push(node->right);
        }
    }
}
int findMinTime(Node* target, unordered_map<Node*, Node*> &mp){
    queue<Node*> q;
    unordered_set<Node*> st;
    q.push(target);
    st.insert(target);
    
    int time = 0;
    
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i<sz; i++){
            auto node = q.front();
            q.pop();
            //now go on all three directions 
            if(node->left && st.count(node->left) == 0){
                q.push(node->left);
                st.insert(node->left);
            }
            if(node->right && st.count(node->right) == 0){
                q.push(node->right);
                st.insert(node->right);
            }
            if(mp[node] && st.count(mp[node]) == 0){
                q.push(mp[node]);
                st.insert(mp[node]);
            }
        }
        time++;
    }
    return time-1;
}
int minTime(Node* root, int target) 
{
    if(root == NULL)    return 0;
    //find the target node address 
    Node* targetNode = NULL;
    findTarget(root, target, targetNode);
    
    //now lets create the parent pointers 
    unordered_map<Node*, Node*> mp;
    findParents(root, mp);
    
    return findMinTime(targetNode, mp);
}
int main()
{
    return 0;
}