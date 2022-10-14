class Solution {
public:
    stack<char>st;
    bool isValid(string s) {
        bool ans=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[' || s[i]=='(' || s[i]=='{')
                st.push(s[i]);
            else
            {
                if(s[i]==')')
                {
                    if(st.empty() || st.top() != '(')
                        return 0;
                    st.pop();
                }
                else if(s[i]==']')
                {
                    if(st.empty() || st.top() != '[')
                        return 0;
                    st.pop();
                }
                else
                {
                    if(st.empty() || st.top() != '{')
                        return 0;
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};