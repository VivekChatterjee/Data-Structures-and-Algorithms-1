class RandomizedSet {
public:
    unordered_map<int,int>m;
    int size=0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!m.count(val))
        {
            m[val]++;
            size++;
            return 1;
        }
        else return 0;        
    }
    
    bool remove(int val) {
        if(m.count(val))
        {
            m.erase(val);
            size--;
            return 1;
        }
        else return 0;
    }
    
    int getRandom() {
        int randomIndex = rand() % size;
        int number = -1;
        for(auto i:m)
        {
            if(randomIndex == 0)
            {
                number = i.first;
                break;
            }
            randomIndex--;
        }
        return number;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */