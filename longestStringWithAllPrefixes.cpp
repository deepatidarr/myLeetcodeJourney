//DID THIS USING TRIE DATA STRUCTURE.
#include <bits/stdc++.h> 
class Trie{
    struct Node{
        bool flag = false;
        Node* links[26];

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
    };
Node* root;

public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool searchPrefix(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

};
string completeString(int n, vector<string> &a){
    // Write your code here.
    unordered_set<string> st;
    Trie tri;
    int valid=0;
    vector<string> res;
    for(auto &it: a){
        tri.insert(it);
    }
    for(auto &word: a){
        string prefix="";
        bool f = true;
        for(int i=0; i<word.size(); i++){
            prefix += word[i];
            if(tri.searchPrefix(prefix) == false){
                f = false;
            }
        }
        if(f==true) {
            res.push_back(word);
        }
    }
    sort(res.begin(), res.end());
    string ans = "";
    for(auto &it: res){
        if(it.size() > ans.size()){
            ans = it;
        }
    }
    if(ans.size()==0) return "None";

    return ans;
}
