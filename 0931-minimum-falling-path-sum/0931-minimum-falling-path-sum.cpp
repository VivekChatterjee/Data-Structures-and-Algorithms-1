class Solution {
public:
    int path(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        int m=matrix.size();
        if(i<0 || j<0 || i >= m || j>=m) return 1e9;
        if(i==m-1) return matrix[i][j];
        if(dp[i][j] != 1e9) return dp[i][j];
        int down=0,downLeft=0,downRight=0;
        // down
        down+=matrix[i][j]+path(i+1,j,matrix,dp);
        // downLeft
        downLeft+=matrix[i][j]+path(i+1,j-1,matrix,dp);
        // downRight
        downRight+=matrix[i][j]+path(i+1,j+1,matrix,dp);
        return dp[i][j]=min(down, min(downLeft, downRight));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        vector<vector<int>>dp(m,vector<int>(m,1e9));
        int mini=INT_MAX;
        for(int i=0;i<m;i++)
            mini=min(mini, path(0,i,matrix, dp));
        return mini;
    }
};