/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
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
NodeValue maxSumBSThelper(TreeNode* root){
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = maxSumBSThelper(root->left);
        auto right = maxSumBSThelper(root->right);

        if(left.maxNode < root->data && right.minNode > root->data){
            //valid BST
            return NodeValue(min(left.minNode, root->data), max(root->data, right.maxNode), 1 + right.maxSum + left.maxSum);
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }
int largestBST(TreeNode * root){
    return maxSumBSThelper(root).maxSum;
}
