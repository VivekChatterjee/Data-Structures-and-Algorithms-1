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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL)
            return {};
        q.push(root);
        vector<vector<int>>v;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>vec;
            for(int i=0;i<n;i++)
            {
                TreeNode* num=q.front();
                // cout<<num->val<<endl;
                vec.push_back(num->val);
                if(num->left)
                    q.push(num->left);
                if(num->right)
                    q.push(num->right);
                
                q.pop();
            }
            v.push_back(vec);
        }
        
        return v;
    }
};