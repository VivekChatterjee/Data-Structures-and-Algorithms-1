class Solution {
public:
    bool isValid(int cur, int op, vector<int> nums)
    {
        int n = nums.size(), count = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] > cur)
            {
                if(nums[i] % cur == 0) count += (nums[i]/cur - 1);
                else count += (nums[i] / cur);
            }            
            if(count > op) return 0;
        }
        return 1;
    }
    int minimumSize(vector<int>& nums, int op) {
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN;
        for(int i: nums) maxi = max(maxi, i);
        int low = 1 , high = maxi, ans = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high- low)/2;
            if(isValid(mid, op, nums))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};