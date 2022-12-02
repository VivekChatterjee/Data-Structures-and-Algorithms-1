class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;
        int i=0, j=0, n=nums.size();
        int cur = 0;
        while(j < n)
        {
            cur+=nums[j];
            if(cur >= target)
            {
                mini = min(mini, j-i+1);
                while(cur >= target)
                {
                    cur-=nums[i];
                    i++;
                    if(cur >= target) mini = min(mini, j-i+1);
                }
            }
            j++;           
        }
        if(mini == INT_MAX) mini=0;
        return mini;
    }
};