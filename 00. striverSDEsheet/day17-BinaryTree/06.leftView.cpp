#include<iostream>
using namespace std;
//Approach 1 -> iterative -> BFS
void solve(Node* root, vector<int> &ans){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        int leftMostVal;
        int flag = 0;
        for(int i = 0; i<sz; i++){
            auto node = q.front();
            q.pop();
            if(flag == 0){
                leftMostVal = node->data;
                flag = 1;
            }
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(leftMostVal);
    }
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(root == NULL) return ans;
   solve(root, ans);
   return ans;
}
// Apporoach 2 -> recursive way 
void solve(Node* root, int l, vector<int> &ans){
    if(root == NULL)    return ;
    if(ans.size() == l) ans.push_back(root->data);
    solve(root->left, l+1, ans);
    solve(root->right, l+1, ans);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   solve(root, 0, ans);
   return ans;
}
int main()
{
    return 0;
}