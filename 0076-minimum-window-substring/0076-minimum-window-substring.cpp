class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(char c:t)
            m[c]++;
        int count = m.size();
        int i=0,j=0;
        int ans=INT_MAX;
        string res="", cur="";
        while(j<s.size())
        {
            if(m.count(s[j]))
            {
                m[s[j]]--;
                if(m[s[j]] == 0)
                    count--;
            }
            while(count == 0 && i<=j)
            {
                if(j-i+1 < ans)
                {
                    res = s.substr(i, j-i+1);
                    ans= min(ans, j-i+1);
                }
                if(m.count(s[i]))
                {
                    m[s[i]]++;
                    if(m[s[i]] > 0)
                        count++;
                }
                i++;
            }
            j++;
        }
        return res;
    }
};