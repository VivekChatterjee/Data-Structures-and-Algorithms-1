class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {
    }
    int next(int price) {
        int currentStreak = 1;
        while(!s.empty() && s.top().first <= price)
        {
            int previousStreak = s.top().second;
            currentStreak+=previousStreak;
            s.pop();
        }
        s.push({price, currentStreak});
        return currentStreak;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */