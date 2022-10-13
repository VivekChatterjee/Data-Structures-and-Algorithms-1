#define vc vector
class Solution {
public:
    vc<vc<int>>ans;
    void solve(vc<int>& c, int t, vc<int>v, int i)
    {
        if(i>=c.size())
        {
            if(t == 0)
                ans.push_back(v);   
            return;
        }
        if(c[i] <= t)
        {
            // picked, staying on current index
            v.push_back(c[i]);
            solve(c,t-c[i] ,v,i);
            v.pop_back();
        }
        // current element not picked
        solve(c,t,v,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vc<int>v;
        solve(c,t,v,0);
        return ans;
    }
};