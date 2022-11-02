class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        
        if(n==1)
            return s;
        
        int dp[n][n];
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            
            if(i!=n-1 && s[i]==s[i+1])
                dp[i][i+1]=1;
            
            else if(i!=n-1 && s[i]!=s[i+1])
                dp[i][i+1]=0;
        }
        
        
        int strt,end;
        int maxi=INT_MIN;
        
        
        for(int k=1;k<n;k++)
        {
            for(int i=0,j=k;i<n && j<n;i++ && j++)
            {
                
                if(dp[i][j]==-1)
                {
                    if(s[i] == s[j] && dp[i+1][j-1] == 1)
                    {
                        dp[i][j]=1;
                        
                        if(j-i+1 > maxi)
                        {
                            strt=i;
                            end=j;
                            maxi=j-i+1;
                        }
                    }
                    
                    else
                    {
                        dp[i][j]=0;
                    }
                }
                
                else if(dp[i][j]==1 && j-i+1 > maxi)
                {
                        strt=i;
                        end=j;
                        maxi=j-i+1;
                }
                
            }
        }
        
        string st=s.substr(strt, end-strt+1);
        return st;
        
    }
};