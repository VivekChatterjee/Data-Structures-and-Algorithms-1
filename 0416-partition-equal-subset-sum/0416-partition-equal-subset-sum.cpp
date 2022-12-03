class Solution {
public:
    bool partition(int i, int target, vector<int>& nums, vector<vector<int>>&dp)
    {
        int n = nums.size();
        if(target == 0) return 1;
        if(i >= n || target < 0) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        int dont=0, pick=0;
        dont = partition(i+1, target, nums, dp);
        pick = partition(i+1, target-nums[i], nums, dp);
        return dp[i][target] = (dont || pick);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i: nums) sum+=i;
        if(sum % 2 != 0) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum/2+1, -1));
        return (partition(0, sum/2, nums, dp))? 1 : 0;
    }
};