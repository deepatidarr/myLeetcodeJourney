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
public:
    int ans;
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ans;
    }
    int helper(TreeNode* node){
        if(node==NULL) return 0;

        int left = helper(node->left);
        int right = helper(node->right);

        int l=0, r=0;

        if(node->left!=NULL && node->left->val == node->val){
            l += (left+1);
        }
        if(node->right!=NULL && node->right->val == node->val){
            r += (right+1);
        }
        ans = max(ans, l+r);
        return max(l,r);
    }
};
