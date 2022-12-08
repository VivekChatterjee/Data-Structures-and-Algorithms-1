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
    vector<int>first, second;
    void dfs(TreeNode* root, bool left)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            if(left) first.push_back(root->val);
            else second.push_back(root->val);
            return;
        }
        dfs(root->left, left);
        dfs(root->right, left);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        bool left = 1;
        dfs(root1, left);
        dfs(root2, !left);
        
        for(int i = 0; i < first. size(); i++)
            if(first[i] != second[i]) return 0;
        return first.size() == second.size();
    }
};