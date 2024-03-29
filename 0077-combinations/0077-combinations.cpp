class Solution {
public:
    vector<vector<int>>ans;
    void comb(int num, int n, int k, vector<int>&v)
    {
        if(num>n || v.size()==k)
        {
            if(v.size() == k) ans.push_back(v);
            return;
        }
        // dont
        comb(num+1, n, k, v);
        // take
        v.push_back(num);
        comb(num+1, n, k, v);
        v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        comb(1, n, k, v);
        return ans;
    }
};