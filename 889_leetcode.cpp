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
    int pre_i=0, post_i=0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* node = new TreeNode(preorder[pre_i]);
        pre_i++;

        if(node->val  != postorder[post_i])
            node->left = constructFromPrePost(preorder, postorder);
        if(node->val != postorder[post_i])
            node->right = constructFromPrePost(preorder, postorder);
        
        post_i++;

        return node;
    }
};
