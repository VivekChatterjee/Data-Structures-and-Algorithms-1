class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>grt;
        int n = nums.size();
        for(int i=n-1; i>=0; i--) grt.push(nums[i]);
        vector<int>ans;
        for(int i=n-1; i>=0; i--)
        {
            while(!grt.empty() && grt.top() <= nums[i]) grt.pop();
            ans.push_back((grt.empty())? -1 : grt.top());
            grt.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};