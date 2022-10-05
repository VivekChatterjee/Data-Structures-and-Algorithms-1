class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev=nums[0];
        int maxSum=prev;
        for(int i=1;i<nums.size();i++)
        {
            prev=max(prev+nums[i],nums[i]);
            maxSum=max(maxSum,prev);
        }
        return maxSum;
    }
};