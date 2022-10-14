class MyQueue {
public:
    
    stack<int>s,st;
    
    void push(int x) {
        
         while(!s.empty()) {
            st.push(s.top());
            s.pop();
        }
        st.push(x);
        while(!st.empty()) {
            s.push(st.top());
            st.pop();
        }
    }
    
    int pop() {
        int a=s.top();
        s.pop();
        return a;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */