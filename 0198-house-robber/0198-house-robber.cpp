class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0], prev2=0, take=0,dont=0;
        for(int i=1;i<n;i++)
        {
            take = nums[i];
            if(i > 1) take+= prev2;
            dont=prev;
            int cur = max(take, dont);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};