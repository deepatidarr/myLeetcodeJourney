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
    int dfs(TreeNode* root, unordered_map<TreeNode*, int> &dp){
        if(root == NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        //memoization
        if(dp[root]) return dp[root];

        int pick = root->val;
        if(root->left && root->left->left) pick += dfs(root->left->left, dp);
        if(root->left && root->left->right) pick += dfs(root->left->right, dp);
        if(root->right && root->right->left) pick += dfs(root->right->left, dp);
        if(root->right && root->right->right) pick += dfs(root->right->right, dp);

        int notPick = 0;
        if(root->left) notPick += dfs(root->left, dp);
        if(root->right) notPick += dfs(root->right, dp);

        return dp[root] = max(pick, notPick);
        
    }
public:
    int rob(TreeNode* root) {
        int ans = 0;
        unordered_map<TreeNode*, int> dp;
        ans = dfs(root, dp);
        return ans;
    }
};
