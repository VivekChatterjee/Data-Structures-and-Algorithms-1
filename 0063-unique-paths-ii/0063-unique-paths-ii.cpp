class Solution {
public:
    int paths(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0 && obstacleGrid[i][j] == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int up=0, left=0;
        // up
        up+=paths(i-1,j,obstacleGrid,dp);
        // left
        left+=paths(i,j-1,obstacleGrid,dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return paths(m-1, n-1, obstacleGrid, dp);
    }
};