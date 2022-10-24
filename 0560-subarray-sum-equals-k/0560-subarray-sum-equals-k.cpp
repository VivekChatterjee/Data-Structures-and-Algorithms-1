class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c=0;
        int n=nums.size();
        int sum=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k)
                c++;
            if(m.count(sum-k))
                c+=m[sum-k];
            m[sum]++;
        }
        
        return c;
    }
};