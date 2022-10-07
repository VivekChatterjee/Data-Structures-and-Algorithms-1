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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>in;
        for(int i=0;i<inorder.size();i++)
            in[inorder[i]] = i;
        
        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, in);
        return root;
    }
    
    TreeNode* build(vector<int>& preorder, int preSt, int preEnd , vector<int>& inorder, int inSt, int inEnd, unordered_map<int,int>&in)
    {
        if(preSt > preEnd || inSt > inEnd)
            return  NULL;
        
        TreeNode* root = new TreeNode( preorder[preSt] );
        int indexOfRoot = in[root->val];
        int numsInLeft = indexOfRoot - inSt;
        
        root->left = build(preorder, preSt+1, preSt+numsInLeft , inorder, inSt, indexOfRoot-1, in);
        root->right = build(preorder, preSt+numsInLeft+1, preEnd , inorder, indexOfRoot+1, inEnd, in);  
        
        return root;
    }
    
};