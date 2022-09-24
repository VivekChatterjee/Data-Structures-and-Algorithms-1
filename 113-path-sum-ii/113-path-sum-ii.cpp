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
    
    void dfs(TreeNode* root, vector<int>v, vector<vector<int>>&ans, int t, int sum)
    {
        if(root==NULL)
            return;
        
        sum=sum+root->val;
        v.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL && sum==t)
        {
            ans.push_back(v);
            v.pop_back();
            return;
        }
        
        // cout<<sum<<" ";
        // cout<<"S"<<sum<<endl;
        
        dfs(root->left,v,ans,t,sum);
        dfs(root->right,v,ans,t,sum);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        
        if(root==NULL)
            return {};
        
        vector<int>v;
        // v.push_back(root->val);
        vector<vector<int>>ans;
        dfs(root,v,ans,t,0);
        // dfs(root->left,v,ans,t,root->val);
        // dfs(root->right,v,ans,t,root->val);
        return ans;
    }
};