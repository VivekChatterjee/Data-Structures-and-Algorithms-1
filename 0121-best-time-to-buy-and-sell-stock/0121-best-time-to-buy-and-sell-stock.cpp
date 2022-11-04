class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN;
        int leastPrice = INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            leastPrice = min(leastPrice, prices[i]);
            profit = max(profit, prices[i]-leastPrice);
        }
        return profit;
    }
};