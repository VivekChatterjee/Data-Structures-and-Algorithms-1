/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode* , TreeNode*> parents;
    void findParents(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left)
                {
                    parents[node->left]=node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    parents[node->right]=node;
                    q.push(node->right);
                }
            }
        }            
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        findParents(root);
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*, bool>vis;
        vis[target]=true;
        int cur=0;
        while(!q.empty())
        {
            int n=q.size();
            if(cur++ == k) break;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right])
                {
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(parents[node] && !vis[parents[node]])
                {
                    vis[parents[node]]=true;
                    q.push(parents[node]);
                }
            }
        }
        
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};