/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        recover(root);
    }
    unordered_set<int> st;
    void recover(TreeNode* root){
        queue<TreeNode*> q; q.push(root);
        while(q.size()){
            TreeNode* node = q.front(); q.pop();
            int x = node->val;
            st.insert(x);
            if(node->left){
                TreeNode* left = node->left;
                left->val = 2*x+1;
                q.push(left);
            }
            if(node->right){
                TreeNode* right = node->right;
                right->val = 2*x+2;
                q.push(right);
            }
        }
    }
    
    bool find(int target) {
        if(st.find(target) == st.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
