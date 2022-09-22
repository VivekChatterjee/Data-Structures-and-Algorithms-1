class Solution {
public:
    string reverseWords(string s) {
        s+=' ';
        string ans="",word="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
                word+=s[i];
            else
            {
                reverse(word.begin(),word.end());
                ans+=word+' ';
                word="";
            }
        }
        ans.pop_back();
        return ans;
    }
};