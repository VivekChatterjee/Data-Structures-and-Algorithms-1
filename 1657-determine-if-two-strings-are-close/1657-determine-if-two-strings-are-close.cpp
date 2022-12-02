class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return 0;
        unordered_map<char,int>m1, m2;
        for(char c:word1) m1[c]++;
        for(char c:word2)
        {
            if(!m1.count(c)) return 0;
            m2[c]++;
        }
        vector<int>v1, v2;
        for(auto i:m1) v1.push_back(i.second);
        for(auto i:m2) v2.push_back(i.second);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return (v1 == v2);
    }
};