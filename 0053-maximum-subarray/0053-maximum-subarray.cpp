class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sumEndsHere = 0;
        int start = 0, end = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sumEndsHere+=nums[i];
            if(sumEndsHere > ans)
            {
                ans = sumEndsHere;
                end = i;
            }
            if(sumEndsHere < 0)
            {
                sumEndsHere = 0;
                start = i+1;
            }
        }
        return ans;
    }
};