class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        int n=inter.size();
        vector<vector<int>>ans;
        for(int i=0; i<n; i++)
        {
            int lastNum = (ans.empty())? INT_MAX : ans.back()[1];
            if(ans.empty() || lastNum < inter[i][0])
                ans.push_back( {inter[i][0] , inter[i][1]});
            else
            {
                if(max(lastNum, inter[i][1]) > lastNum)
                {
                    lastNum = max(lastNum, inter[i][1]);
                    ans.back()[1] = lastNum;
                }
            }
        }
        return ans;
    }
};