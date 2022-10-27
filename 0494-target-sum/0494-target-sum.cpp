class Solution {
public:
    int ans=0;
    void find(int i, int sum, vector<int>&nums, int target)
    {
        if(i==nums.size())
        {
            if(sum == target) ans++;
            return;
        }
        // take -ve
        find(i+1,sum-nums[i],nums,target);
        // take +ve
        find(i+1,sum+nums[i],nums,target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        find(0,0,nums,target);
        return ans;
    }
};