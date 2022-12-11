class Solution {
private:
    int pathSum(TreeNode* root, int &path)
    {
        if(root==NULL)
            return 0;
        
        int left=pathSum(root->left,path);
        int right=pathSum(root->right,path);
        left=(left<0)?0:left;
        right=(right<0)?0:right;
        path=max(path,(root->val+left+right));
        
        return (root->val+ max(left,right));
    }
public:
    int maxPathSum(TreeNode* root) {
        int path=INT_MIN;
        int completePathSum=pathSum(root,path);
        return path;
    }
};