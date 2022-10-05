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
    
    void set(int &val, TreeNode* root, int cur, int depth)
    {
        if(root==NULL || cur>depth)
            return;
        if(cur==depth)
        {
            TreeNode *left= new TreeNode(val);
            TreeNode *right= new TreeNode(val);
            left->left=root->left;
            right->right=root->right;
            root->left=left;
            root->right=right;
            return;            
        }
        set(val,root->left,cur+1,depth);
        set(val,root->right,cur+1,depth);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL)
            return root;
        
        if(depth==1)
        {
            TreeNode *cur=new TreeNode(val);
            cur->left=root;
            return cur;
        }
        else
        {
            set(val, root,1, depth-1);
            return root;
        }
    }
};