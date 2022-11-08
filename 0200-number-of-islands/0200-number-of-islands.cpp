class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int i, int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=1;
        if(i+1 < m)
        {
            if(!vis[i+1][j] && grid[i+1][j]=='1') dfs(grid, vis, i+1, j);
        }
        if(j+1 < n)
        {
            if(!vis[i][j+1] && grid[i][j+1]=='1') dfs(grid, vis, i, j+1);
        }
        if(i-1>=0)
        {
            if(!vis[i-1][j] && grid[i-1][j]=='1') dfs(grid, vis, i-1, j);
        }
        if(j-1>=0)
        {
            if(!vis[i][j-1] && grid[i][j-1]=='1') dfs(grid, vis, i, j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return ans;
        
        // 1 1 1
        // 0 1 0
        // 1 1 1
    }
};