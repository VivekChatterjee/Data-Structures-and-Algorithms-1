#define pp pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i:nums)
            m[i]++;
        
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        
        for(auto i:m)
        {
            pq.push({i.second,i.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int>v;
        
        while(pq.size()>0)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        
        return v;
    }
};