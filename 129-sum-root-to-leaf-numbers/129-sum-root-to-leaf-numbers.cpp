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
    
    ll dfs(TreeNode* root, ll num)
    {
        if(root == NULL) return 0;
        num = num*10 + (ll) root->val;
        if(root->left == NULL && root->right == NULL) return num;
        ll left = dfs(root->left, num);
        ll right = dfs(root->right, num);
        return left+right;
    }
    
    int sumNumbers(TreeNode* root) {
        ll num = 0;
        ll ans = dfs(root, num);
        return ans;
    }
};