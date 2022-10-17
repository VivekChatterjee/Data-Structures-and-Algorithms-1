#define vc vector
#define ll long long int
class Solution {
public:
    int dp[201][201];
    int path(vc<vc<int>>&tri, int i, int j, int des)
    {
        if(i<0 || i>des || j<0 || j>=tri[i].size())
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==des)
            return tri[i][j];
        ll down=0, dia=0;
        // down
        down=tri[i][j]+path(tri,i+1,j,des);
        //diagonal
        dia=tri[i][j]+path(tri,i+1,j+1,des);
        return dp[i][j]=min(down,dia);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return path(triangle, 0,0, triangle.size()-1);
    }
};