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
class Solution {
private:
    void dfs(TreeNode* root, int t, vector<vector<int>>& res, vector<int>& v){
        if(root != NULL && root->left == NULL && root->right==NULL){
            t -= root->val;
            v.push_back(root->val);
            if(t==0){
                res.push_back(v);
            }
            t += root->val;
            v.pop_back();
            return;
        }
        if(root){
            t -= root->val;
            v.push_back(root->val);
            dfs(root->left, t, res, v);
            dfs(root->right, t, res, v);
            t += root->val;
            v.pop_back();
        }
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> res;
        vector<int> v;
        dfs(root, t, res, v);
        return res;
    }
};
