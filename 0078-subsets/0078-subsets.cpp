class Solution {
public:
    vector<vector<int>> ans;    
    void solve(vector<int>v, vector<int>&nums, int i)
    {
        if(i>=nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        // do not take the current element
        solve(v,nums,i+1);
        
        // take the current element
        v.push_back(nums[i]);
        solve(v,nums,i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        solve(v,nums,0);
        return ans;
    }
};