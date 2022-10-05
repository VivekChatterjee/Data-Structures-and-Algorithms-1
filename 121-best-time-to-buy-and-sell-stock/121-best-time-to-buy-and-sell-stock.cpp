class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i:prices)
        {
            mini=min(mini,i);
            maxi=max(maxi,i-mini);
        }
        return maxi;
    }
};