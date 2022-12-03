class Solution {
public:
    // using kadane
    int maxSubArray(vector<int>& nums) {
        int s=0, e=0;
        int ans=nums[0], cur=0;
        int n = nums.size();
        while(e<n)
        {
            cur+=nums[e];
            ans = max(ans, cur);
            if(cur < 0)
            {
                cur=0;
                s=e+1;
            }
            e++;
        }
        return ans;
    }
};