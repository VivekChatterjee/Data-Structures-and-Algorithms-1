// space optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>prev(n,0);
        prev[0]=grid[0][0];
        for(int j=1;j<n;j++) prev[j]= grid[0][j]+prev[j-1];
        for(int i=1;i<m;i++)
        {
            vector<int>cur(n,0);
            for(int j=0;j<n;j++)
            {
                cur[j]=grid[i][j];
                int mini=20001;
                mini=min(mini, prev[j]);
                if(j>0)
                    mini=min(mini, cur[j-1]);
                cur[j]+=mini;
            }
            prev=cur;
        }
        return prev[n-1];
    }
};


// tabulation
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,0));
//         dp[0][0]=grid[0][0];
//         for(int i=1;i<m;i++) dp[i][0]= grid[i][0]+dp[i-1][0];
//         for(int j=1;j<n;j++) dp[0][j]= grid[0][j]+dp[0][j-1];
//         for(int i=1;i<m;i++)
//         {
//             for(int j=1;j<n;j++)
//             {
//                 dp[i][j]=grid[i][j]+min(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };





// memoization
// class Solution {
// public:
//     int pathSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
//     {
//         if(i<0 || j<0) return 20001;
//         if(i==0 && j==0) return grid[i][j];
//         if(dp[i][j] != -1) return dp[i][j];
//         int up=0, left=0;
//         // up
//         up+=grid[i][j]+pathSum(i-1,j,grid,dp);
//         // left
//         left+=grid[i][j]+pathSum(i,j-1,grid,dp);
//         return dp[i][j]=min(up,left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return pathSum(m-1, n-1, grid, dp);
//     }
// };