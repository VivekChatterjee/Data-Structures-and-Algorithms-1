class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>> ans;
        int n=in.size();
        for(int i=0;i<n;i++)
        {
            if(ans.empty() || ans.back()[1] < in[i][0])
                ans.push_back({in[i][0], in[i][1]});
            else
                ans.back()[1] = max(ans.back()[1], in[i][1]);
        }
        return ans;
    }
};