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
    
    bool valid(TreeNode* root, long mini, long maxi)
    {
        if(root == NULL) return 1;
        
        if(root->val <= mini || root->val >= maxi)
        return 0;
        
        bool left = valid(root->left, mini, root->val);
        bool right = valid(root->right, root->val, maxi);
        return left && right;
            
    }
    
    
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};