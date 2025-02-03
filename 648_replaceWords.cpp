class Trie {

    struct Node{
        Node* links[26];
        bool flag = false;

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

        string checkDerivative(string word){
            Node* node = root;
            string der = "";
            for(int i=0; i<word.size(); i++){
                if(node->containsKey(word[i])) {
                    der += word[i];
                    node = node->get(word[i]);
                    if(node->getEnd() == true) {
                        return der;
                    }
                }
                else{
                    return word;
                }
            }
            return word;
        }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie tri;
        for(auto& it: dictionary){
            tri.insert(it);
        }
        int n = sentence.size();
        string word="";
        vector<string> words;
        for(int i=0; i<n; i++){
            if(sentence[i] == ' '){
                words.push_back(word);
                word = "";
            }
            else {    
                word += sentence[i];
            }
        }
        words.push_back(word);
        string ans = "";
        for(auto &s: words){
            ans += tri.checkDerivative(s);
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
