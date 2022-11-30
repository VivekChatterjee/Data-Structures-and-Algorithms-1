class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m1, m2;
        for(int i: arr) m1[i]++;
        for(auto i: m1)
        {
            if(!m2.count(i.second))
                m2[i.second]++;
            else return 0;
        }
        return 1;
    }
};