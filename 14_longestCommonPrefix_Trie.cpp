//  THIS METHOD USES TRIE DATA STRUCTURE TO FIND THE SOLUTION
class Trie {

struct Node{
    Node* links[26];
    bool flag = false;
    int commonPrefix = 0;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
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
    void increasePrefix(){
        commonPrefix++;
    }
    int getPrefixes(){
        return commonPrefix;
    }
};
private: 
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->setEnd(); //sets the flag to true for the last trie
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return true;
    }

    int prefixes(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            node = node->get(word[i]);
        }
        return node->getPrefixes();
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie tri;
        for(auto &s: strs){
            tri.insert(s);
        }
        string ans = "";
        string s = strs[0];
        string tmp="";
        for(int i=0; i<s.size(); i++){
            tmp += s[i];
            if(tri.prefixes(tmp) == strs.size()){
                ans = tmp;
            } 
        }
        return ans;
    }
};class Trie {

struct Node{
    Node* links[26];
    bool flag = false;
    int commonPrefix = 0;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
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
    void increasePrefix(){
        commonPrefix++;
    }
    int getPrefixes(){
        return commonPrefix;
    }
};
private: 
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->setEnd(); //sets the flag to true for the last trie
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return true;
    }

    int prefixes(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            node = node->get(word[i]);
        }
        return node->getPrefixes();
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie tri;
        for(auto &s: strs){
            tri.insert(s);
        }
        string ans = "";
        string s = strs[0];
        string tmp="";
        for(int i=0; i<s.size(); i++){
            tmp += s[i];
            if(tri.prefixes(tmp) == strs.size()){
                ans = tmp;
            } 
        }
        return ans;
    }
};
