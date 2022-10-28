// memoization
class Solution {
public:
    int pathSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i<0 || j<0) return 20001;
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int up=0, left=0;
        // up
        up+=grid[i][j]+pathSum(i-1,j,grid,dp);
        // left
        left+=grid[i][j]+pathSum(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return pathSum(m-1, n-1, grid, dp);
    }
};