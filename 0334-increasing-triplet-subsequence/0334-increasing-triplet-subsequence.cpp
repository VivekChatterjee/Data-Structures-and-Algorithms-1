class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return 0;
        vector<int>rightMax;
        int n = nums.size();
        int maxi=INT_MIN;
        for(int i = n-1;i>=0;i--)
        {
            rightMax.push_back(maxi);
            maxi=max(maxi, nums[i]);
        }
        reverse(rightMax.begin(), rightMax.end());
        int mini = nums[0];
        bool ans=false;
        for(int i=1;i<n;i++)
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