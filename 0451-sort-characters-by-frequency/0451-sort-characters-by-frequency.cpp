class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(char c:s) m[c]++;
        priority_queue<pair<int,char>>p;
        for(auto i:m)
        {
            p.push({i.second, i.first});
        }
        string ans="";
        while(!p.empty())
        {
            int num=p.top().first;
            char c=p.top().second;
            while(num--) ans+=c;
            p.pop();
        }
        return ans;
    }
};