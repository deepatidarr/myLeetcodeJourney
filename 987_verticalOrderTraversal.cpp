/*
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        // we will consider both horizontal level and vertical level.
        map<int,map<int,multiset<int>>> mp; // vertical levle, <horizontal level, multiset>
        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root, {0, 0}});
        while(q.size()){
            auto it = q.front(); q.pop();

            TreeNode* node = it.first;
            int vertical = it.second.first;
            int horizontal = it.second.second;

            mp[vertical][horizontal].insert(node->val);

            if(node->left){
                q.push({node->left, {vertical-1, horizontal+1}});
            }
            if(node->right){
                q.push({node->right, {vertical+1, horizontal+1}});
            }
        }

        for(auto &it: mp){
            vector<int> tmp;
            for(auto &i: it.second){
                for(auto &val: i.second){
                    tmp.push_back(val);
                }
            }
            res.push_back(tmp);
        }

        return res;
    }
};
