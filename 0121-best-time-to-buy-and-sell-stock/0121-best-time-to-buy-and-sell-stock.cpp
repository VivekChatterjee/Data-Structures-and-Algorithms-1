class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=INT_MIN;
        int mini=INT_MAX;
        for(int i=0; i <prices.size(); i++)
        {
            mini=min(mini, prices[i]);
            profit=max(profit, prices[i] - mini);
        }
        return profit;
    }
};