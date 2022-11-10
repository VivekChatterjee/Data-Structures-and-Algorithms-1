class StockSpanner {
public:
    stack<pair<int,int>>s;
    int i=0;
    bool smallerExist=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!s.empty() && s.top().first <= price)
        {
            smallerExist=1;
            s.pop();
        }
        int count = 1;
        if(smallerExist && s.empty()) count = i - (-1);
        else if(!s.empty()) count = i - s.top().second;
        s.push({price, i});
        i++;
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */