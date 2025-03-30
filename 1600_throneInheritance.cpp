class ThroneInheritance {
struct Node{
    string name;
    vector<Node*> children;

    Node(string name){
        this->name=name;
    }
};

public:
    Node* root;
    unordered_set<string> dead;
    unordered_map<string,Node*> mp;

    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        mp[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        Node *parent = mp[parentName];
        Node *child = new Node(childName);
        mp[childName] = child;
        (parent->children).push_back(child);
    }
    
    void death(string name) {
        dead.insert(name);
    }

    void preorder(vector<string> &res, Node *node, unordered_set<string> &dead){
        if(!node) return;

        if(dead.find(node->name)==dead.end()){
            res.push_back(node->name);
        }

        for(auto &it: node->children){
            preorder(res, it, dead);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        preorder(res, root, dead);
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
