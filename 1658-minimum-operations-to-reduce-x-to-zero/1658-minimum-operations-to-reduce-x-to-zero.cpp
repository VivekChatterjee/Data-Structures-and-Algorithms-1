class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0, n = nums.size();
        for (int i : nums)
            sum += i;
        int t = sum - x;
        int cur = 0, maxL = 0;
        int start = 0;
        
        int s = 0;
        for (int end = 0; end < n; end++)
        {
            cur += nums[end];
            while (start <= end && cur > t)
            {
                cur -= nums[start];
                start += 1;
            }
            if (cur == t)
            {
                s = 5;
                maxL = max(maxL, end - start + 1);
            }
        }
        if (s == 5)
            return (n - maxL);
        else
            return -1;
    }
};