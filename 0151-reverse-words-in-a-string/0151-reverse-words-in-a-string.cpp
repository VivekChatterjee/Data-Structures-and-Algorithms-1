class Solution {
public:
    string reverseWords(string s) {
        s+=' ';
        stack<string>word;
        string wd="";
        for(int i=0; i<s.size(); i++)
        {
            if(wd.size()>0 && s[i] == ' ')
            {
                word.push(wd);
                wd="";
            }
            else if(s[i] != ' ')
                wd+=s[i];                
        }
        string ans="";
        while(!word.empty())
        {
            ans+=word.top()+" ";
            word.pop();
        }
        ans.pop_back();
        return ans;
    }
};