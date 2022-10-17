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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* prev=root,*cur=root;
        while(root)
        {
            if(root->val < val)
            {
                prev=root;
                root=root->right;
            }
            else
            {
                prev=root;
                root=root->left;
            }
        }
        if(prev->val < val)
            prev->right = new TreeNode(val);
        else
            prev->left = new TreeNode(val);
        
        return cur;
    }
};