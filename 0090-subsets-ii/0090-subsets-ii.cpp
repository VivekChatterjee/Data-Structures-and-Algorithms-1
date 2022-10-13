#define vc vector
class Solution {
public:
    vc<vc<int>>ans;
    void solve(vc<int>&nums,int i, vc<int>v)
    {
        ans.push_back(v);
        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1]) continue;
            // take current
            v.push_back(nums[j]);
            solve(nums,j+1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vc<int>v;
        solve(nums, 0, v);
        return ans;
    }
};