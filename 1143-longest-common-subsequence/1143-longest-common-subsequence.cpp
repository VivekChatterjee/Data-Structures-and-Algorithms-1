class Solution {
public:
    int dp[1001][1001];
    int lcs(string &t1, string &t2, int m, int n)
    {
        if(m<0 || n<0)
            return 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(t1[m]==t2[n])
            return dp[m][n]=1+lcs(t1,t2,m-1,n-1);
        else
            return dp[m][n]=max(lcs(t1,t2,m-1,n), lcs(t1,t2,m,n-1));
    }
    
    int longestCommonSubsequence(string t1, string t2) {
        memset(dp, -1, sizeof(dp));
        return lcs(t1,t2,t1.size()-1,t2.size()-1);
    }
};