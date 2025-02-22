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
    void printLevel(TreeNode* root){
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,vector<TreeNode*>> mp;
        while(q.size()){
            auto it = q.front(); q.pop();
            TreeNode* node = it.first;
            int level = it.second;
            mp[level].push_back(node);

            if(node->left) q.push({node->left, level+1});
            if(node->right) q.push({node->right, level+1});
        }
        for(auto &it: mp){
            cout<<it.first<<" - ";
            for(auto &x: it.second){
                cout<<x->val<<" ";
            }cout<<endl;
        }
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        stack<TreeNode*> nodes;
        int i=0; string tmp="";
        TreeNode* root = NULL;
        while(i<n && traversal[i]!='-'){
            tmp += traversal[i++];
        }
        root = new TreeNode(stoi(tmp));
        nodes.push(root);
        int depth=0;
        while(i<n){
            while(i<n && traversal[i]=='-'){
                depth++; i++;
            }
            tmp="";
            while(i<n && traversal[i]!='-'){
                tmp += traversal[i]; i++;
            }
            TreeNode* newnode = new TreeNode(stoi(tmp));

            //now i have the node formed and its depth

            while(nodes.size() > depth) nodes.pop();

            //now, the new node will go as the child of st.top()
            TreeNode* parent = nodes.top();
            if(parent->left == NULL){
                parent->left = newnode;
            }
            else{
                parent->right = newnode;
            }
            depth=0;
            nodes.push(newnode);
        }
        //printLevel(root);
        return root;
    }

    // void dfs(unordered_map<TreeNode*,int> &mp, vector<TreeNode*> &nodes, TreeNode* node, int index, int level){

    //     if(node==NULL || index>=nodes.size() || (mp[node]+1)!=mp[nodes[index]]) {
    //         return;
    //     }

    //     int lvl = mp[nodes[index]]; // level on which the new node is suppossed to be on

    //     if(node->left==NULL){
    //         node->left = nodes[index];
    //         dfs(mp, nodes, node->left, index+1, level+1);
    //         return;
    //     }
    //     if(node->left!=NULL && node->right==NULL){
    //         node->right = nodes[index];
    //         dfs(mp, nodes, node->right, index+1, level+1);
    //         return;
    //     }
    // }
};
