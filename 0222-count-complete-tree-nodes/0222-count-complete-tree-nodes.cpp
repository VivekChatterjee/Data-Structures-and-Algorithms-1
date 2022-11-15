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
    int total(TreeNode *root)
    {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return 1 + total(root->left)+total(root->right);
    }
    int countNodes(TreeNode* root) {
        return total(root);
    }
};