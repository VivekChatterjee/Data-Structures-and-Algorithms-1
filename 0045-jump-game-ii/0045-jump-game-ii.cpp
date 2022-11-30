class Solution {
public:
    int minJump(int i, vector<int>& nums, vector<int>& dp)
    {
        int n = nums.size();
        if(i == n-1) return 0;
        if(i < 0 || i >= n || nums[i] == 0) return 1e7;
        if(dp[i] != -1) return dp[i];
        int num = nums[i];
        int mini = 1e7;
        for(int j=1; j<=num; j++)
        {
            int cur = 1 + minJump(i+j, nums, dp);
            mini = min(mini, cur);
        }
        return dp[i] = mini;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return minJump(0, nums, dp);
    }
};