class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>>p;
        for(int i=0; i<mat.size(); i++)
        {
            int ct=0;
            for(int j=0; j<mat[i].size(); j++)
            {
                if(mat[i][j] == 0) break;
                else ct++;
            }
            p.push({ct, i});
            if(p.size() > k) p.pop();
        }
        vector<int>ans(k);
        k--;
        while(!p.empty())
        {
            ans[k--] = p.top().second;
            p.pop();
        }
        return ans;
    }
};
