class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m1,m2;
        for(int i=0;i<max(nums1.size(),nums2.size());i++)
        {
            if(i<nums1.size())
                m1[nums1[i]]++;
            if(i<nums2.size())
                m2[nums2[i]]++;
        }
        vector<int>ans;
        for(int i:nums1)
        {
            if(m1.count(i) && m2.count(i))
            {
                ans.push_back(i);
                m1[i]--;
                m2[i]--;
                if(m1[i]==0)
                    m1.erase(i);
                if(m2[i]==0)
                    m2.erase(i);
            }
        }
        return ans;
    }
};