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
    int most=0;
    int findFreq(TreeNode* root, unordered_map<int,int>&m)
    {
        if(!root) return 0;
        if(!root->left && !root->right)
        {
            m[root->val]++;
            most=max(most, m[root->val]);
            return root->val;
        }
        int sum = root->val + findFreq(root->left, m) + findFreq(root->right, m);
        m[sum]++;
        most=max(most, m[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        unordered_map<int,int>m;
        int sum = findFreq(root, m);
        for(auto i: m)
        {
            if(i.second == most) ans.push_back(i.first);
        }
        return ans;
    }
};