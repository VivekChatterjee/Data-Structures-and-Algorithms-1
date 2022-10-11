class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int n = nums.size();
        vector<int>rightMax(n);
        int maxi=INT_MIN;
        for(int i = n-1;i>=0;i--)
        {
            rightMax[i]=maxi;
            maxi=max(maxi, nums[i]);
        }
        int mini = nums[0];
        bool ans=false;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i] > mini && nums[i] < rightMax[i])
            {
                ans=true;
                break;
            }
            mini = min(mini, nums[i]);
        }
        return ans;
    }
};