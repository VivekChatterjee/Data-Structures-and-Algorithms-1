// space optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int>front(m),cur(m);
        for(int j=0;j<m;j++)
            front[j]=triangle[m-1][j];
        for(int i=m-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                cur[j]=triangle[i][j]+min(front[j], front[j+1]);
            }
            front=cur;
        }
        return front[0];
    }
};



// tabulation - striver method
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m=triangle.size();
//         vector<vector<int>>dp(m,vector<int>(m,-1));
//         for(int j=0;j<m;j++)
//         {
//             dp[m-1][j]=triangle[m-1][j];
//         }
//         for(int i=m-2;i>=0;i--)
//         {
//             for(int j=0;j<triangle[i].size();j++)
//             {
//                 dp[i][j]=triangle[i][j]+min(dp[i+1][j], dp[i+1][j+1]);
//             }
//         }
//         return dp[0][0];
//     }
// };


// tabulation - my method
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
        // int m=triangle.size();
        // int n=triangle[m-1].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
//         dp[0][0]=triangle[0][0];
//         for(int i=1;i<m;i++) dp[i][0]=triangle[i][0]+dp[i-1][0];
//         for(int i=1;i<m;i++)
//         {
//             for(int j=1;j<triangle[i].size();j++)
//             {
//                 dp[i][j]=triangle[i][j];
//                 int mini=INT_MAX;
//                 mini=min(mini, dp[i-1][j-1]);
//                 if(j<triangle[i-1].size())
//                     mini=min(mini, dp[i-1][j]);
//                 dp[i][j]+=mini;                    
//             }
//         }
//         int mini=INT_MAX;
//         for(int j=0;j<n;j++)
//             mini=min(mini, dp[m-1][j]);
//         return mini;
//     }
// };



// memoization
// class Solution {
// public:
//     int path(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)
//     {
//         int m=triangle.size();
//         if(i == m-1) return triangle[i][j];
//         if(dp[i][j] != -1) return dp[i][j];
//         int down=0, downRight=0;
//         // down
//         down+=triangle[i][j]+path(i+1,j,triangle,dp);
//         // down and right
//         downRight+=triangle[i][j]+path(i+1,j+1,triangle,dp);
//         return dp[i][j]=min(down,downRight);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m=triangle.size();
//         vector<vector<int>>dp(m,vector<int>(m,-1));
//         return path(0,0, triangle, dp);
//     }
// };