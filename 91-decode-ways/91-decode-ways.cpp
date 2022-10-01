// class Solution {
// public:
//     int dp[101][102];
//     int ways(string &s,int i,int len)
//     {
//         if(i>=s.size())
//         {
//             if(len==s.size())
//                 return 1;
//             else
//                 return 0;
//         }
        
//         int j,k;
//         j=s[i]-'0';
//         if(i+1 < s.size())
//             k=s[i+1]-'0';
//         if(i+1 < s.size() && dp[j][k] != -1)
//             return dp[j][k];
//         else if(i == s.size()-1 && dp[j][101]!=-1)
//             return dp[j][101];
        
//         int oneEl=0, twoEl=0;
//         // take 1 element
//         if(s[i]!='0')
//         oneEl+= ways(s,i+1,len+1);
            
//         // take 2 elements
//         if(i+1 < s.size() && ((s[i]-'0')*10 + (s[i+1]-'0') <=26) && s[i]!='0')
//         twoEl+=ways(s,i+2,len+2);
        
//         if(i+1 < s.size())
//             return dp[j][k]= oneEl+twoEl;
//         else
//             return dp[j][101]= oneEl+twoEl;
//     }
    
//     int numDecodings(string s) {
//         memset(dp,-1,sizeof(dp));
//         // return ways(s,0,0);
//     }
// };

class Solution {
public:
    int numDecodings(string s) {
        vector<int> hg(s.size()+1,0);
        int ans=0;
        ans = recur(s,0,hg);
        return ans;
    }
    int recur(string s, int pos, vector<int>& hg){
        if(pos==s.size())return 1;
        if(s[pos]=='0')return 0;
        if(pos==s.size()-1)return 1;
        if(hg[pos]>0)return hg[pos];
        string b = s.substr(pos,2);
        
        int way1 = recur(s,pos+1,hg);
        int way2=0;
        if(stoi(b)<=26&&stoi(b)>0){
            way2 = recur(s,pos+2,hg);
        }
        hg[pos]= way1+way2;
        return hg[pos];
    }
};




