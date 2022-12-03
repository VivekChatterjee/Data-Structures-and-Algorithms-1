class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n = nums.size(), i = 0, j = 0, sum = 0;
        m[0] = -1;
        while(j < n)
        {
            sum += nums[j];
            sum %= k;
            if(m.count(sum))
            {
                if(j- m[sum] > 1) return 1;
            }
            else m[sum] = j;
            j++;
        }
        return 0;
    }
};