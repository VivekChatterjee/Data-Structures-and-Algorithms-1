class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x = 0;
        for(int i:nums) x^=i;
        for(int i=1;i<=nums.size();i++) x^=i;
        
        int set = x & ~(x-1);
        int a=0,b=0;
        for(int i:nums)
        {
            if(i & set)
                a^=i;
            else
                b^=i;
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(i & set)
                a^=i;
            else
                b^=i;
        }
        vector<int>ans;
        for(int i:nums)
        {
            if(i == a) 
            {
                ans.push_back(a);
                ans.push_back(b);
                return ans;
            }
        }
        ans.push_back(b);
        ans.push_back(a);
        return ans;
    }
};