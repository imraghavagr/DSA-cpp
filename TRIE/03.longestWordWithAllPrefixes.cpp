#include<iostream>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool getEnd(){
        return flag;
    }
};
class Trie{
private:
    Node* root;
public: 
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        //at the last reference, put bool = true
        node->setEnd();
    }
    bool isComplete(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
            if(node->getEnd() == false) return false;
        }
        return true;
    }
};
string longestWord(vector<string>& words) {
    Trie* node = new Trie();
    //insert all the words in the trie 
    for(auto it : words){
        node->insert(it);
    }
    string ans = "";
    for(auto it : words){
        if(node->isComplete(it)){
            if(it.length() > ans.length()){
                ans = it;
            }
            //for getting lexicographically smaller ans
            else if(it.length() == ans.length() && it<ans){
                ans = it;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}