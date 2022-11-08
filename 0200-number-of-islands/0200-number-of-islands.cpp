// class Solution {
// public:
//     void dfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int i, int j)
//     {
//         int m=grid.size();
//         int n=grid[0].size();
//         if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || grid[i][j]=='0') return;
//         vis[i][j]=1;
//         dfs(grid, vis, i+1, j);
//         dfs(grid, vis, i, j+1);
//         dfs(grid, vis, i-1, j);
//         dfs(grid, vis, i, j-1);
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>>vis(m, vector<int>(n,0));
//         int ans=0;
//         for(int i=0; i<m; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 if(!vis[i][j] && grid[i][j] == '1')
//                 {
//                     ans++;
//                     dfs(grid, vis, i, j);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// no need of visited array
class Solution {
public:
    void dfs(vector<vector<char>>& grid,  int i, int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};