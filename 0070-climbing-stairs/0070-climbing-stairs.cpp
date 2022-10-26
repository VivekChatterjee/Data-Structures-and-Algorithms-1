class Solution {
public:
    int climbStairs(int n) {
        // SC = O(n)
        // vector<int> dp(n+1,-1);
        // dp[0]=1;
        // dp[1]=2;
        // for(int i=2;i<n;i++)
        //     dp[i]=dp[i-1]+dp[i-2];
        // return dp[n-1];
        
        // SC = O(1)
        int prev2=1;
        int prev=2;
        if(n==1) return 1;
        for(int i=2;i<n;i++)
        {
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};