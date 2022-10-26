// #include<bits/stdc++.h>
class Solution {
public:
    int climb(int n, vector<int>&dp)
    {
        if(n<3) return dp[n-1];
        if(dp[n] != -1) return dp[n-1];
        return dp[n-1]=climb(n-1,dp)+climb(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=2;
        return climb(n,dp);
        return 1;
    }
};