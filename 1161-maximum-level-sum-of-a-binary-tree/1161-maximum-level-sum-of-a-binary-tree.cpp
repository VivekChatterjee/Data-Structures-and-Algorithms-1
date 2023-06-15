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
    int maxLevelSum(TreeNode* root) {
        int ans=0, cur=1, curSum=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            int sum=0;
            while(n--)
            {
                TreeNode* node=q.front();
                sum+=node->val;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum>curSum)
            {
                ans=cur;
                curSum=sum;
            }
            cur++;
        }
        return ans;        
    }
};