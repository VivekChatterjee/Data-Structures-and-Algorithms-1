class Solution {
public:
    
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size();
        int n=t2.size();
        int dp[m+1][n+1];
        for(int i=1;i<=n;i++)
            dp[0][i]=0;
        for(int i=0;i<=m;i++)
            dp[i][0]=0;        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(t1[i-1] == t2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};