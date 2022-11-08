class Solution {
public:
    void dfs(vector<vector<int>>& c, int j, vector<int>&vis)
    {
        int n=c.size();
        for(int i=0; i<n; i++)
        {
            if(!vis[i] && c[j][i] == 1)
            {
                vis[i]=1;
                if(i!=j)
                dfs(c,i, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& c) {
        int n=c.size();
        int ans=0;
        vector<int>vis(n);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(c,i, vis);
            }
        }
        return ans;
    }
};