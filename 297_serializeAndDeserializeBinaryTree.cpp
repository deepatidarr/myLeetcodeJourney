/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string tree = "";
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* node = q.front(); q.pop();
            
            if(node == NULL) tree += "#,";
            else tree += (to_string(node->val)+',');

            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        //cout<<tree<<endl;
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size(); if(n==0) return NULL;
        stringstream s(data);
        string str;

        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q; q.push(root);

        while(q.size()){
            TreeNode* node = q.front(); q.pop();

            //left child
            getline(s,str,',');
            if(str == "#") node->left = NULL;
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            //right child
            getline(s,str,',');
            if(str == "#") node->right = NULL;
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
