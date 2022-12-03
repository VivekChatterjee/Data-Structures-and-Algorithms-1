class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>m;
        int n = s.size(), i = 0, j = 0, ans = 0;
        while(j < n)
        {
            m[s[j]]++;
            if(j-i+1 == m.size()) ans = max(ans, j-i+1);
            while((j-i+1) > m.size())
            {
                m[s[i]]--;
                if(m[s[i]] == 0) m.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};