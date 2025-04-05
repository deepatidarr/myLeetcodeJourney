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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right= lowestCommonAncestor(root->right,p, q);

        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;
        map<int,vector<TreeNode*>> mp;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        int l=0;
        while(q.size()){
            auto n = q.front(); q.pop();
            int level = n.first;
            TreeNode* node = n.second;
            mp[level].push_back(node);

            if(node->left){
                q.push({level+1,node->left});
            }
            if(node->right){
                q.push({level+1, node->right});
            }
            l = max(l,level);
        }
        vector<TreeNode*> deepest = mp[l];
        int d = deepest.size();
        if(d==1) return deepest[0];
        TreeNode* res = deepest[0];
        for(int i=1; i<d; i++){
            res = lowestCommonAncestor(root, res, deepest[i]);
        }
        return res;
    }
};
