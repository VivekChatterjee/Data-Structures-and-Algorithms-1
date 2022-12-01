class CustomStack {
public:
    int maxS = 0;
    vector<int>v;
    CustomStack(int maxSize) {
        maxS = maxSize;
    }
    
    void push(int x) {
        if(v.size() < maxS) v.push_back(x);
    }
    
    int pop() {
        if(v.empty()) return -1;
        else
        {
            int back = v.back();
            v.pop_back();
            return back;
        }
    }
    
    void increment(int k, int val) {
        if(v.size() < k) k = v.size();
        for(int i=0; i<k; i++)
            v[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */