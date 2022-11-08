class Solution {
public:
    int c;
    void bfs(vector<vector<int>>& image, vector<vector<int>>& vis, int i, int j, int curColor)
    {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int, int>>q;
        q.push({i, j});
        while(!q.empty())
        {
            int curi=q.front().first;
            int curj=q.front().second;
            image[curi][curj]=c;
            vis[curi][curj]=1;
            q.pop();
            
            int left=curj-1;
            int right=curj+1;
            int up=curi-1;
            int down=curi+1;
            
            if(left>=0 && !vis[curi][left] && image[curi][left]==curColor)
            {
                q.push({curi, left});
            }
            if(right<n && !vis[curi][right] && image[curi][right]==curColor)
            {
                q.push({curi, right});
            }
            if(up>=0 && !vis[up][curj] && image[up][curj]==curColor )
            {
                q.push({up, curj});                
            }
            if(down<m && !vis[down][curj] && image[down][curj]==curColor)
            {
                q.push({down, curj});     
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>vis(m, vector<int>(n));
        c=color;
        if(image[sr][sc] != color && !vis[sr][sc])
        bfs(image, vis, sr, sc, image[sr][sc]);
        return image;
    }
};