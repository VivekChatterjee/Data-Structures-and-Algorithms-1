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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=INT_MAX;
        while(!q.empty())
        {
            int n=q.size();
            bool found = false;
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(!found)
                {
                    ans=node->val;
                    found=!found;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};