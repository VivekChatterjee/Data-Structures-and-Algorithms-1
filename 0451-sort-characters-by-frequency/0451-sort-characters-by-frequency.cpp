class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int>v;
        for(char c:s) v[c]++;
        multiset<pair<int, char>>all;
        for(int i=1; i<126; i++)
        {
            if(v[i] != 0) all.insert({v[i] , (char)i});
        }
        string ans="";
        for(auto it= all.rbegin(); it!=all.rend(); it++)
        {
            int num = it->first;
            while(num--) ans+=it->second;
        }
        return ans;
    }
};