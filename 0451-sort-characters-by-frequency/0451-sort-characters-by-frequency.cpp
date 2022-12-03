// class Solution {
// public:
//     string frequencySort(string s) {
//         vector<char>v(126);
//         for(char c:s) v[c]++;
//         vector<pair<int,char>>all;
//         for(int i=1; i<126; i++)
//         {
//             if(v[i] != 0) all.push_back({v[i] , (char)i});
//         }
//         sort(all.begin(), all.end(), greater<pair<int,char>>());
//         string ans="";
//         for(auto i: all)
//         {
//             while(i.first--) ans+=i.second;            
//         }
//         return ans;
//     }
// };
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