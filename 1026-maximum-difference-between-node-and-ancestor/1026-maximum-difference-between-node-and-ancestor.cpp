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
    int ans = 0;
    void solve(TreeNode* root, TreeNode* trav)
    {
        if(!trav) return;
        ans = max(ans, abs(root->val - trav->val));
        solve(root, trav->left);
        solve(root, trav->right);
    }
    void ancestor(TreeNode* root)
    {
        if(!root) return;
        solve(root, root);
        ancestor(root->left);
        ancestor(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        ancestor(root);
        return ans;
    }
};