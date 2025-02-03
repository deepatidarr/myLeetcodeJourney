#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int countPrefix = 0;
    int countEndsWith = 0;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void increasePrefix(){
        countPrefix++;
    }

    void increaseEndsWith(){
        countEndsWith++;
    }

    int getEndsWith(){
        return countEndsWith;
    }

    int getPrefixes(){
        return countPrefix;
    }

    void reducePrefix(){
        countPrefix--;
    }

    void deleteEnd(){
        countEndsWith--;
    }

};
class Trie{
private:
    Node* root;

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEndsWith();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->getEndsWith();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefixes();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else return;
        }
        node->deleteEnd();
    }
};
