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
    int leftHeight(TreeNode *root)
    {
        if(root == NULL) return 0;
        int left = 0;
        left = 1 + leftHeight(root->left);
        return left;
    }
    int rightHeight(TreeNode* root)
    {
        if(root == NULL) return 0;
        int right = 0;
        right = 1 + rightHeight(root->right);
        return right;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int leftHt = leftHeight(root);
        int rightHt = rightHeight(root);
        if(leftHt == rightHt) return ((1 << leftHt) - 1);
        return (1 + countNodes(root->left) + countNodes(root->right));
    }
};