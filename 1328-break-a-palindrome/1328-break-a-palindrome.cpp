class Solution {
public:
    
    bool isPalin(string s)
    {
        int st=0, e=s.size()-1;
        while(st<=e)
        {
            if(s[st]!=s[e]) return 0;
            st++;
            e--;
        }
        return 1;
    }
    
    string breakPalindrome(string p) {
        if(p.size() == 1) return "";
        string ans="";
        int ct=0;
        int i;
        for(i=0;i<p.size();i++)
        {
          if(p[i]!='a' && !isPalin(p.substr(0,i)+'a'+p.substr(i+1,p.size())))
          {
              ct++;
              break;
          }
        }
        if(ct==1) p[i] = 'a';
        else
        {
            p[p.size()-1] = 'b';
        }
        return p;
    }
};