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
                while(cur >= target)
                {
                    mini = min(mini, j-i+1);
                    cur-=nums[i];
                    i++;
                }
                
            }
            j++;           
        }
        return (mini == INT_MAX)? 0 : mini;
    }
};