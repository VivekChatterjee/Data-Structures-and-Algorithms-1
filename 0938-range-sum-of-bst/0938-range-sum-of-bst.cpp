class Solution {
public:
    int sum(TreeNode* root, int l, int h)
    {
        if(!root) return 0;
        int left = 0, right = 0;
        if(root->val >=l && root->val <=h)
        {
            left +=root->val + sum(root->left, l, h);
            right += sum(root->right, l, h);
        }
        else if(root->val < l)
        {
            right += sum(root->right, l, h);
        }
        else left += sum(root->left, l, h);
        return left+right;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sum(root, low, high);
    }
};