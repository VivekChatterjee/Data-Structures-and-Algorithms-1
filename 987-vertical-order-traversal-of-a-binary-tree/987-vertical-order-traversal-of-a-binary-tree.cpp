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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>nodes;
        queue<pair <TreeNode*, pair<int,int>>> q;
        if(root==NULL)
            return {};
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            TreeNode* node = cur.first;
            int x=cur.second.first;
            int y=cur.second.second;
            nodes[x][y].insert(node->val);
            if(node->left)
                q.push({node->left, {x-1,y+1}});
            if(node->right)
                q.push({node->right, {x+1,y+1}});
        }
        vector<vector<int>>ans;
        for(auto i:nodes)
        {
            vector<int>v;
            for(auto j:i.second)
                v.insert(v.end(), j.second.begin(), j.second.end());
            ans.push_back(v);
        }
        
        return ans;
    }
};