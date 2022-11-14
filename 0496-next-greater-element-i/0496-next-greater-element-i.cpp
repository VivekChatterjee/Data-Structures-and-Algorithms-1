class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>great;
        unordered_map<int,int>m;
        for(int i=nums2.size()-1; i>=0; i--)
        {
            while(!great.empty() && great.top() < nums2[i]) great.pop();
            int grt = (great.empty())? -1 : great.top();
            m[nums2[i]] = grt;
            great.push(nums2[i]);
        }
        vector<int>res;
        for(int i=0; i<nums1.size(); i++)
        {
            res.push_back(m[nums1[i]]);
        }
        return res;
    }
};