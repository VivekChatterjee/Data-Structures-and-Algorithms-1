#define vc vector
class Solution {
public:
    vc<vc<int>>ans;
    void solve(vc<int>&c, int t, vc<int>&v, int i)
    {
        if(t == 0)
        {
            ans.push_back(v);
            return;
        }        
        for(int j=i;j<c.size();j++)
        {
            if(j>i && c[j]==c[j-1]) continue;
            if(c[j]>t) break;
            v.push_back(c[j]);
            solve(c,t-c[j],v,j+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>&c, int t) {
        sort(c.begin(),c.end());
        vc<int>v;
        solve(c,t,v,0);
        return ans;
    }
};
