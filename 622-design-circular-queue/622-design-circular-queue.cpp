class MyCircularQueue {
public:
    
    vector<int>ans;
    int size;
    
    MyCircularQueue(int k) {
        size=k;
    }
    
    bool enQueue(int value) {
        if(ans.size() >= size)
            return 0;
        else
        {
            ans.push_back(value);
            return 1;
        }
    }
    
    bool deQueue() {
        if(ans.size()==0)
            return 0;
        else
        {
            ans.erase(ans.begin());
            return 1;
        }
    }
    
    int Front() {
        return (ans.size()==0)? -1 : ans.front();
    }
    
    int Rear() {
        return (ans.size()==0)? -1 : ans.back();
    }
    
    bool isEmpty() {
        return (ans.size()==0);
    }
    
    bool isFull() {
        return (ans.size()==size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */