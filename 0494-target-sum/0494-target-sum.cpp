class Solution {
public:
    int find(int i, int sum, vector<int>&nums, int target, vector<vector<int>>&dp)
    {
        if(i == nums.size()-1)
        {
            if(sum + nums[i] == target && sum - nums[i] == target) return 2;
            else if(sum + nums[i] == target || sum - nums[i] == target) return 1;
            else return 0;
        }
        if(dp[i][sum+1000] != -1) return dp[i][sum+1000];
        int neg = 0, pos = 0;
        // take -ve
        neg = find(i+1,sum-nums[i],nums,target,dp);
        // take +ve
        pos = find(i+1,sum+nums[i],nums,target,dp);
        return dp[i][sum+1000] = neg + pos;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(21, vector<int>(2001, -1));
        return find(0,0,nums,target,dp);
        // tabulation
    }
};

// 20 * -1000 to 20 * 1000