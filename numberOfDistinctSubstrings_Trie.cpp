struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }

};

int countDistinctSubstrings(string &s)
{
    Node* root = new Node();
    int n = s.size();
    int cnt = 0;
    
    for(int i=0; i<n; i++){
        Node* node = root;
        for(int j=i; j<n; j++){
            if(!node->containsKey(s[j])){
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return cnt+1;
}
