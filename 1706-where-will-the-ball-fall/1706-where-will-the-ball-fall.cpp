class Solution {
public:
    int ball(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || j>=n || (grid[i][j]==1 && j+1<n && grid[i][j+1]==-1) || (grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==1))
        {
            // cout<<grid[i][j]<<" i="<<i<<" j="<<j<<endl;
            return -1;
        }
        if(i==m-1)
        {
            if(grid[i][j]==1)
            {
                if(j+1<n)
                {
                    if(grid[i][j+1]!=-1) return j+1;
                    else return -1;                        
                }
                return -1;
            }
            else
            {
                if(j-1>=0)
                {
                    if(grid[i][j-1]!=1) return j-1;
                    else return -1;    
                }
                return -1;
            }
        }
        int right=-1, left=-1;
        // go right
        if(grid[i][j]==1)
            right=ball(i+1, j+1, grid, dp);
        else
            left=ball(i+1, j-1, grid, dp);
        
        if(left==-1 && right==-1)
        {
            return -1;
        }
        else
        {
            if(left!=-1) return left;
            else return right;
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        vector<int>ans;
        for(int j=0; j<n; j++)
        {
            if(n==1) ans.push_back(-1);
            else ans.push_back(ball(0, j, grid, dp));
        }
        return ans;
    }
};