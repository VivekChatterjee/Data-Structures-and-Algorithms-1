class Solution {
public:
    int dp[101];
    int ways(string &s,int i,int len)
    {
        if(i>=s.size())
        {
            if(len==s.size())
                return 1;
            else
                return 0;
        }
        
        if(dp[i]!=-1)
            return dp[i];
        
        int w=0;
        int oneEl=0, twoEl=0;
        // take 1 element
        if(s[i]!='0')
        oneEl+= ways(s,i+1,len+1);
        // take 2 elements
        if(i+1 < s.size() && s[i]!='0' && ((s[i]-'0')*10 + (s[i+1]-'0') <=26))
        twoEl+=ways(s,i+2,len+2);
        w=oneEl+twoEl;
        return dp[i]=w;
    }
    
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return ways(s,0,0);
    }
};
