class RandomizedCollection {
public:
    unordered_map<int,int>m;
    vector<int>v;
    RandomizedCollection() {
        
    }
    bool insert(int val) {
        if(!m.count(val))
        {
            m[val]++;
            v.push_back(val);
            return 1;
        }
        else
        {
            m[val]++;
            v.push_back(val);
            return 0;        
        }
    }
    
    bool remove(int val) {
        if(m.count(val))
        {
            m[val]--;
            v.erase(find(v.begin(), v.end(), val));
            if(m[val] == 0) m.erase(val);
            return 1;
        }
        else return 0;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */