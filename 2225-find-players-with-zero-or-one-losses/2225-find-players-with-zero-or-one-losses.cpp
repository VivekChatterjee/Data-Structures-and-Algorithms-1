class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>>m; //number, played matches, lost matches
        int size = matches.size();
        for(int i=0; i<size; i++)
        {
            int p1 = matches[i][0];
            int p2 = matches[i][1];
            m[p1].first++;
            m[p2].second++;
        }
        vector<vector<int>>ans(2);
        for(auto i:m)
        {
            if(i.second.first >= 1 && i.second.second == 0) ans[0].push_back(i.first);
            if(i.second.second == 1) ans[1].push_back(i.first);
        }
        return ans;
    }
};