class MyCalendarThree {
public:
    int maxi=1;
    map<int, int>m;
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int maxi=0,cnt=0;
        for(auto i:m)
        {
            cnt+=i.second;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */