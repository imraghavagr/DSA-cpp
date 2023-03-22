struct Node{
    Node* links[26];
    int endsWith = 0;
    int countPrefix = 0;
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void increaseCountPrefix(){
        countPrefix += 1;
    }
    void increaseEndsWith(){
        endsWith += 1;
    }
    int getEndsWithCount(){
        return endsWith;
    }
    int getPrefixCount(){
        return countPrefix;
    }
    void decreasePrefixCount(){
        countPrefix -= 1;
    }
    void decreaseEndsWith(){
        endsWith -= 1;
    }
};
class Trie {
    //root of the trie 
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                //put it 
                node->put(ch, new Node());
            }
            node = node->get(ch);
            //now increae the count prefix
            node->increaseCountPrefix();
        }
        //once the word is completed, increase endsWith
        node->increaseEndsWith();
    }
    
    int countWordsEqualTo(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return 0;
            }
            node = node->get(ch);
        }
        return node->getEndsWithCount();
    }
    
    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for(char ch : prefix){
            if(!node->containsKey(ch)){
                return 0;
            }
            node = node->get(ch);
        }
        return node->getPrefixCount();
    }
    
    void erase(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return;
            }
            node = node->get(ch);
            node->decreasePrefixCount();
        }
        node->decreaseEndsWith();
    }
};

#include<iostream>
using namespace std;
int main()
{   
    Trie* node = new Trie();
    node->insert("apple");
    node->insert("apple");
    node->insert("apps");
    node->insert("apps");
    return 0;
}