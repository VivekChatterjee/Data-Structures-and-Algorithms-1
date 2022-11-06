class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>t(n+1);
        int ans = -1;
        for(int i=0; i<trust.size(); i++)
        {
            int normal = trust[i][0];
            int maybeJudge = trust[i][1];
            t[normal]--;
            t[maybeJudge]++;
        }
        for(int i=1; i<=n; i++)
        {
            if(t[i] == n-1)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};