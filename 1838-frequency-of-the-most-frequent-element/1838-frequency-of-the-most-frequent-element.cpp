#define ll long long int
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxFreq = 1;
        int n = nums.size();
        if(n == 1) return maxFreq;
        int start = 0, end = 1;
        ll opt = 0;
        sort(nums.begin(), nums.end());
        while(start <= end && end < n)
        {
            opt+= (ll)((ll)(nums[end] - nums[end-1]) * (ll)(end - start));
            if(opt <= k) maxFreq = max(maxFreq, end-start+1);
            else
            {
                while(opt > k)
                {
                    opt-= (ll)nums[end] - nums[start];
                    start++;
                }
                opt = max((ll)0, opt);
                if(opt <= k) maxFreq = max(maxFreq, end-start+1);
            }
            end++;
        }
        return maxFreq;
    }
};