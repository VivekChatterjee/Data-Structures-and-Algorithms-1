// space optimization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>row(n,1);
        for(int i=1;i<m;i++)
        {
            vector<int>r(n);
            for(int j=0;j<n;j++)
            {
                r[j]=row[j];
                if(j>0)
                r[j]+=r[j-1];
            }
            row=r;
        }
        return row[n-1];
    }
};


// tabulation
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         for(int i=0;i<m;i++) dp[i][0]=1;
//         for(int j=1;j<n;j++) dp[0][j]=1;
//         for(int i=1;i<m;i++)
//             for(int j=1;j<n;j++)
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
//         return dp[m-1][n-1];
//     }
// };



// memoization
// class Solution {
// public:
//     int paths(int i, int j, vector<vector<int>>&dp)
//     {
//         if(i==0 && j==0) return 1;
//         if(i<0 || j<0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int up=0,left=0;
//         // up
//         up+=paths(i-1,j,dp);
//         // left
//         left+=paths(i,j-1,dp);
//         return dp[i][j]=up+left;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         return paths(m-1,n-1,dp);
//     }
// };