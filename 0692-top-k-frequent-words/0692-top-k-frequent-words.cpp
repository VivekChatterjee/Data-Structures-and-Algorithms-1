class Solution {
public:
    bool static compare(pair<int,string> a, pair<int,string> b)
    {
        if(a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        for(auto i:words)
            m[i]++;
        vector<pair<int,string>>v;
        for(auto it=m.rbegin();it!=m.rend();it++)
        {
            v.push_back({it->second, it->first});
        }
        sort(v.begin(),v.end(),compare);
        vector<string>ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].second);
        return ans;
    }
};