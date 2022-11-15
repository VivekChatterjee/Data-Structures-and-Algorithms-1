class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(nums[i])) return nums[i];
            m[nums[i]]++;
        }
        return ans;
    }
};