#include<iostream>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;
    //will check if there exists a given char
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
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    //O(length of the word)
    void insert(string word) {
        Node* node = root; // dummy variable 
        //iterate throught the word 
        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                //if it does not contain the word 
                //we need to create it 
                node->put(word[i], new Node());
            }
            //moves to the reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    //O(length of word)
    bool search(string word) {
        //start with the root node 
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return (node->isEnd() == true);
    }
    //O(length of prefix)
    bool startsWith(string prefix) {
        //start with the root node 
        Node* node = root;
        for(int i = 0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
int main()
{
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("apps");
    obj->insert("appxl");
    obj->insert("bac");
    obj->insert("bat");

    cout<<obj->search("appxl")<<endl;
    cout<<obj->search("bac")<<endl;
    cout<<obj->startsWith("app")<<endl;
    cout<<obj->startsWith("aappd")<<endl;
    return 0;
}