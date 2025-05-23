/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void pre(Node* root, vector<int> &res){
        if(root == NULL){
            return;
        }
        
        res.push_back(root->val);
        for(auto &it: root->children){
            pre(it, res);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        pre(root, res);
        return res;
    }
};
