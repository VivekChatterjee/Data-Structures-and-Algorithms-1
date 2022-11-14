class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>great;
        vector<int>ans;
        for(int i=nums2.size()-1; i>=0; i--)
        {
            while(!great.empty() && great.top() < nums2[i]) great.pop();
            ans.push_back((great.empty())? -1 : great.top());
            great.push(nums2[i]);
        }
        reverse(nums2.begin(), nums2.end());
        unordered_map<int,int>m;
        for(int i=0; i<nums2.size(); i++)
        {
            m[nums2[i]] = ans[i];
        }
        vector<int>res;
        for(int i=0; i<nums1.size(); i++)
        {
            res.push_back(m[nums1[i]]);
        }
        return res;
    }
};