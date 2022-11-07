class Solution {
public:
    int find(int i, int sum, vector<int>&nums, int target, vector<vector<int>>&dp)
    {
        if(i == nums.size())
        {
            if(sum == target) return 1;
            else return 0;
        }
        
        if(sum<0)
        {
            if(dp[i][sum+2001] != -1) return dp[i][sum+2001];
        }
        else
        {
            if(dp[i][sum] != -1) return dp[i][sum];
        }
        
        int neg = 0, pos = 0;
        
        // take -ve
        neg = find(i+1,sum-nums[i],nums,target,dp);
        
        // take +ve
        pos = find(i+1,sum+nums[i],nums,target,dp);
        if(sum < 0) return dp[i][sum+1001] = neg+pos;
        return dp[i][sum] = neg + pos;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(23, vector<int>(3003, -1));
        return find(0,0,nums,target,dp);
    }
};

// 20 * -1000 to 20 * 1000