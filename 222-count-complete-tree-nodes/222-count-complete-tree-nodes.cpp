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
    
    int leftHeight(TreeNode* root)
    {
        int ht=0;
        while(root)
        {
            ht++;
            root=root->left;
        }
        return ht;
    }
    
    int rightHeight(TreeNode* root)
    {
        int ht=0;
        while(root)
        {
            ht++;
            root=root->right;
        }
        return ht;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left=leftHeight(root);
        int right=rightHeight(root);
        if(left == right)
            return (1<<left)-1;
            // return pow(2,left)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};