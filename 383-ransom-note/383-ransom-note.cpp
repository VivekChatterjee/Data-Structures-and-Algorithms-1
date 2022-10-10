class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m;
        for(char c:magazine)
            m[c]++;
        
        int n=ransomNote.size();
        int len=0;
        for(char c:ransomNote)
        {
            if(m[c]>0)
            {
                len++;
                m[c]--;
            }
        }
        
        if(len==n)
            return 1;
        
        else
            return 0;
    }
};