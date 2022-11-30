class Solution {
public:
    bool reach(int i, vector<int>& arr, vector<int>& dp)
    {
        int n = arr.size();
        if(i < 0 || i >= n) return 0;
        if(arr[i] == 0) return 1;
        if(dp[i] != -1) return dp[i];
        int num = arr[i];
        arr[i] = 1e5;
        bool cur = false;
        cur = (reach(i + num, arr, dp) || reach(i - num, arr, dp));
        arr[i] = num;        
        return dp[i] = cur;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>dp(arr.size(), -1);
        return reach(start, arr, dp);
    }
};