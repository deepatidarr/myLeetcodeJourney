class Solution {
private:
    void post(Node* root, vector<int> &res){
        if(root == NULL){
            return;
        }
        
        for(auto &it: root->children){
            post(it, res);
            //res.push_back(it->val);
        }
        res.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        post(root, res);
        return res;
    }
};
