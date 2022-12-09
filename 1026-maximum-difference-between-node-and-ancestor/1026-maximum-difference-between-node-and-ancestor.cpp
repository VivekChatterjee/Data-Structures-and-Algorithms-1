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
    int ancestor(TreeNode* root, int mini, int maxi)
    {
        if(!root) return (maxi - mini);
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        return max(ancestor(root->left, mini, maxi), ancestor(root->right, mini, maxi));
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini = INT_MAX, maxi = INT_MIN;
        return ancestor(root, mini, maxi);
    }
};