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
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*>par;
        par[root] = NULL;
        queue<TreeNode*>q;
        q.push(root);
        int sum = 0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(par.count(node) && par[node])
                {
                    if(par.count(par[node]) && par[par[node]])
                    {
                        int num = (par[par[node]])->val;
                        if(num % 2 == 0)
                        {
                        //     cout<<num<<" > "<<node->val<<endl;
                            sum+=node->val;
                        }
                    }
                }
                if(node->left)
                {
                    q.push(node->left);
                    par[node->left] = node;
                }
                if(node->right)
                {
                    q.push(node->right);
                    par[node->right] = node;
                }
            }
        }
        return sum;
    }
};