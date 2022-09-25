class MyCircularQueue {
public:
    queue<int>q;
    int size;
    MyCircularQueue(int k) {
        size=k;
    }
    
    bool enQueue(int value) {
        if(q.size()>=size)
            return 0;
        else
        {
            q.push(value);
            return 1;
        }
    }
    
    bool deQueue() {
        if(q.empty())
            return 0;
        
        else
        {
            q.pop();
            return 1;
        }
    }
    
    int Front() {
        return (q.empty())? -1 : q.front();
    }
    
    int Rear() {
        return (q.empty())? -1 : q.back();
    }
    
    bool isEmpty() {
        return (q.empty());
    }
    
    bool isFull() {
        if(q.size() == size)
            return 1;
        else return 0;
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