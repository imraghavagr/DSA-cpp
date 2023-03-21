#include<iostream>
using namespace std;
struct Node{
    Node* links[26];
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
int countDistinct(string s) {
    int ans = 0;
    Node* root = new Node();
    for(int i = 0; i<s.length(); i++){
        Node* node = root;
        for(int j = i; j<s.length(); j++){
            if(!node->containsKey(s[j])){
                ans++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return ans;
}
int main()
{
    return 0;
}