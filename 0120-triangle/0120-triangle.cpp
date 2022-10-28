// memoization
class Solution {
public:
    int path(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        int m=triangle.size();
        int n=triangle[i].size();
        if(j>=n) return 1e9;
        if(i == m-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down=0, downRight=0;
        // down
        down+=triangle[i][j]+path(i+1,j,triangle,dp);
        // down and right
        downRight+=triangle[i][j]+path(i+1,j+1,triangle,dp);
        return dp[i][j]=min(down,downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(0,0, triangle, dp);
    }
};