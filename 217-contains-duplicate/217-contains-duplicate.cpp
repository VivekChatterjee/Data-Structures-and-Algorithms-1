class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        for(int i:nums)
            s.insert(i);
        
        if(s.size() == n)
            return 0;
        else
            return 1;
    }
};