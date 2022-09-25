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
        dfs(root->left,v,ans,t,sum);
        dfs(root->right,v,ans,t,sum);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>>ans;
        vector<int>v;
        if(root==NULL)
            return {};
        dfs(root,v,ans,t,0);
        return ans;
    }
};