class Solution {
public:
    bool jump(int i, vector<int>&nums, vector<int>&dp)
    {
        int n = nums.size();
        if(i == n-1) return 1;
        if(i >= n || nums[i] == 0) return 0;
        if(dp[i] != -1) return dp[i];
        int num = nums[i];
        bool found = false;
        for(int j=1; j<=num; j++)
        {
            dp[i] = jump(i+j, nums, dp);
            if(dp[i]) break;
        }
        return dp[i];
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return jump(0, nums, dp);
    }
};