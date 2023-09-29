class Solution {
public:
    bool monotone(vector<int>& nums, bool ascending)
    {
        if(ascending)
        {
            for(int i=1; i<nums.size(); i++)
            {
                if(nums[i]<nums[i-1])
                return 0;
            }
            return 1;
        }
        else
        {
            for(int i=1; i<nums.size(); i++)
            {
                if(nums[i]>nums[i-1])
                return 0;
            }
            return 1;
        }
    }
    bool isMonotonic(vector<int>& nums) {
        return monotone(nums, 0) || monotone(nums, 1);
    }
};