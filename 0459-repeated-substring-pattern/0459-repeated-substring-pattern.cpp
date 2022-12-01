class Solution {
public:
    bool isSame(int i, string &cur, string &s)
    {
        int n = s.size();
        int curn = cur.size();
        if(i == n) return 0;
        string now = "";
        while(curn--)
        {
            if(i == n) return 0;
            now+=s[i];
            i++;
        }
        if(now != cur) return 0;
        else if(now == cur && i == n) return 1;
        else return isSame(i, cur, s);
    }
    bool repeatedSubstringPattern(string s) {
        bool ans = false;
        int n = s.size();
        string cur="";
        for(int i = 0; i < n; i++)
        {
            if(cur.empty()) cur+=s[i];
            else
            {
                if(s[i] == cur[0])
                {
                    if(isSame(i, cur, s)) return 1;
                }
                cur+=s[i];
            }
        }
        return 0;
    }
};