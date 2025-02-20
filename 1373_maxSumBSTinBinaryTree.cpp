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
class NodeValue{
public:
    int minNode, maxNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};
class Solution {
    NodeValue maxSumBSThelper(TreeNode* root, int &ans){
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = maxSumBSThelper(root->left, ans);
        auto right = maxSumBSThelper(root->right, ans);

        if(left.maxNode < root->val && right.minNode > root->val){
            //valid BST
            ans = max(ans, root->val + right.maxSum + left.maxSum);
            return NodeValue(min(left.minNode, root->val), max(root->val, right.maxNode), root->val + right.maxSum + left.maxSum);
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        auto tmp = maxSumBSThelper(root, ans).maxSum;
        return ans;
    }
};
