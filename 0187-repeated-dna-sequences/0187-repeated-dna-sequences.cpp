class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>m;
        int start=0,end=0;
        string res="";
        while(start <= end && end < s.size())
        {
            res+=s[end];
            if(end-start+1 == 10)
            {
                m[res]++;
                res.erase(res.begin());
                start++;
            }
            end++;
        }
        vector<string>ans;
        for(auto i:m)
        {
            if(i.second > 1) ans.push_back(i.first);
        }
        return ans;
    }
};