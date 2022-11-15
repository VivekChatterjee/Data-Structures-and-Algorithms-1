class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        int n=inter.size();
        vector<vector<int>>ans;
        for(int i=0; i<n; i++)
        {
            int s=inter[i][0];
            int e=inter[i][1];
            if(!ans.empty())
            {
                if(s <= ans.back()[1]) continue;
            }
            for(int j=i+1; j<n; j++)
            {
                if(inter[j][0] <= e)
                {
                    e=max(e, inter[j][1]);
                    s=min(s, inter[j][0]);
                }
            }
            ans.push_back({s, e});
        }
        return ans;
    }
};