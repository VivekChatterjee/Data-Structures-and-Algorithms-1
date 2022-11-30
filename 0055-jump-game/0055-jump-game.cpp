class Solution {
public:
    // bool jump(int i, vector<int>&nums, vector<int>&dp)
    // {
    //     int n = nums.size();
    //     if(i == n-1) return 1;
    //     if(i >= n || nums[i] == 0) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int num = nums[i];
    //     bool found = false;
    //     for(int j=1; j<=num; j++)
    //     {
    //         dp[i] = jump(i+j, nums, dp);
    //         if(dp[i]) break;
    //     }
    //     return dp[i];
    // }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        // return jump(0, nums, dp);
        dp[n-1] = 1;
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 1; j <= nums[i]; j++)
            {
                if(i+j >= n) break;
                if(dp[i+j])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};