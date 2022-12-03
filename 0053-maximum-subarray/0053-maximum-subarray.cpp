class Solution {
public:
    // using kadane
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int i=0, ans=nums[0], cur=0, start = 0, end = 0;
        while(i<n)
        {
            cur+=nums[i];
            if(cur > ans)
            {
                ans = cur;
                end = i;
            }
            if(cur < 0)
            {
                cur=0;
                start = i+1;
            }
            i++;
        }
        // cout<<end-start+1<<endl; for length
        return ans;
    }
};