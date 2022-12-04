#define ll long long int
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll sum = 0 , n = nums.size(), ans = 0, mini = INT_MAX, prev = 0, lSum = 0;
        for(ll i: nums) sum+=(ll)i;
        for(ll i = 0; i < n; i++)
        {
            // nums[i] += prev;
            lSum+=nums[i];
            // ll first = ((ll)nums[i]) / (i+1);
            ll first = ((ll)lSum) / (i+1);
            ll last = 0;
            if(i != n-1)
            last = (sum - (ll)lSum) / (n-i-1); 
            ll cur = abs(first - last);
            // cout<<nums[i]<<" ";
            if(cur < mini)
            {
                mini = cur;
                ans = i;
            }
            // prev = nums[i];
        }
        return ans;
    }
};