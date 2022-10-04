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
    vector<string>ans;
    void getPath(TreeNode* root, string v)
    {
        if(!root)return;
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(v);
            return;
        }
       if(root->left)
        getPath(root->left,v+"->"+to_string(root->left->val));
        if(root->right)
        getPath(root->right,v+"->"+to_string(root->right->val));        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string v;
        if(!root) return ans;
        getPath(root,to_string(root->val));
        return ans;
    }
};