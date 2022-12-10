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
    ll K = 1e9+7, ans = 0;
    unordered_map<TreeNode*, ll>m;
    ll sumTree(TreeNode* root)
    {
        if(!root) return 0;
        return m[root] = root->val + sumTree(root->left) + sumTree(root->right);
    }
    void productTree(TreeNode* root, ll total)
    {
        if(!root) return;
        ll lSum = 0, rSum = 0;
        if(root->left)
        {
            // lSum = sumTree(root->left) ;
            lSum = m[root->left];
            rSum = total - lSum ;
            ll pro = (ll)lSum * (ll)rSum;
            ans = max(ans, pro);
        }
        if(root->right)
        {
            // rSum = sumTree(root->right);
            rSum = m[root->right];
            lSum = total - rSum ;
            ll pro = (ll)lSum * (ll)rSum;
            ans = max(ans, pro);
        }
        productTree(root->left, total);
        productTree(root->right, total);
    }
    int maxProduct(TreeNode* root) {
        ll totalSum = sumTree(root);
        productTree(root, totalSum);
        return ans % K;
    }
};