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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>m;
        queue<pair<TreeNode*, int>>q;
        vector<int>ans;
        if(root==NULL)
            return ans;
        q.push({root,0});
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            TreeNode* node=cur.first;
            
            int level=cur.second;
            
            if(!m.count(level))
            m[level]=node->val;
            
            if(node->right)
                q.push({node->right, level+1});
            if(node->left)
                q.push({node->left, level+1});                
        }
        for(auto i:m)
            ans.push_back(i.second);
        return ans;
    }
};