class Solution {
public:
    int squares(vector<int>&sq, int i, int target, vector<vector<int>>&dp)
    {
        if(target < 0 || i < 0) return 1e8;
        if(target == 0) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        int take = 0, dont = 0;
        take = 1 + squares(sq, i, target-sq[i], dp);
        dont+= squares(sq, i-1, target, dp);
        return dp[i][target] = min(take, dont);
    }
    int numSquares(int n) {
        vector<int>sq;
        for(int i=1; i*i <= n; i++)
        {
            sq.push_back(i*i);
        }
        int size = sq.size();
        vector<vector<int>>dp(size+1, vector<int>(n+1, -1));
        return squares(sq, size-1, n, dp);        
    }
};

// 1 4 9 16