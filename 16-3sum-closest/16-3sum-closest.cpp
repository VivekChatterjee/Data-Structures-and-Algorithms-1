class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int cur=nums[0]+nums[1]+nums[2];
        int ans=cur;
        int diff = abs(target-cur);
        for(int i=0; i<n-2; i++)
        {
            int start = i+1;
            int end = n-1;
            while(start<end)
            {
                cur = nums[i] + nums[start] + nums[end];
                if(cur == target || abs(target-cur) < diff)
                {
                    if(cur == target)
                        return cur;
                    diff = min(diff,abs(target-cur)) ;
                    ans=cur;
                }
                
                if(cur > target)
                    end--;
                
                else
                    start++;
            }
        }
        return ans;
    }
};