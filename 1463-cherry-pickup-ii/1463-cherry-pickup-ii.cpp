class Solution {
public:
    int chocolates(int i, int alexaj, int bobj, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
    int r=grid.size();
    int c=grid[0].size();
    if(alexaj < 0 || alexaj >= c || bobj < 0 || bobj >= c || alexaj == bobj) return 0;
    if(i == r-1) return grid[i][alexaj] + grid[i][bobj];
    if(dp[i][alexaj][bobj] != -1) return dp[i][alexaj][bobj];
    int maxx=grid[i][alexaj] + grid[i][bobj];
    int maxi=INT_MIN;
    for(int j=-1; j<2;j++)
    {
        for(int jj=-1;jj<2;jj++)
        {
            maxi=max(maxi, chocolates(i+1, alexaj+j, bobj+jj, grid, dp));
        }
    }
    return dp[i][alexaj][bobj] = maxx+maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>>dp(r, vector<vector<int>>(c,vector<int>(c,-1)));
        return chocolates(0,0,c-1,grid,dp);
    }
};