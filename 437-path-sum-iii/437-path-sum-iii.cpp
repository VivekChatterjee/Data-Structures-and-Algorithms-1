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
#define ll long long int
class Solution {
public:
    int count=0;
    void dfs(TreeNode* root, ll sum, ll t)
    {
        if(root==NULL)
            return;
        sum+=root->val;
        if(sum==t)
            count++;
        // with current sum
        dfs(root->left,sum,t);
        dfs(root->right,sum,t);
    }
    
    int pathSum(TreeNode* root, int t) {
        
        if(root==NULL)
            return 0;
        int sum=0;
        dfs(root,(ll)sum,(ll)t);
        if(root->left)
            pathSum(root->left,t);
        if(root->right)
            pathSum(root->right,t);
        return count;
    }
};