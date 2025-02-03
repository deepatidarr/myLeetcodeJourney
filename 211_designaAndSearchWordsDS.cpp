struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        if(ch=='.') return true;
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
class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                //we must add the node
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool searchUtil(Node* root, string word){
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(word[i]=='.'){
                for(int j=0; j<26; j++){
                    if(node->links[j] != NULL){
                        if(searchUtil(node->links[j], word.substr(i+1))==true){
                            return true;
                        }
                    }
                }
                return false;
            }

            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    bool search(string word) {
        return searchUtil(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
