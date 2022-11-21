class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>>q;
        q.push({entrance[0], entrance[1]});
        int m = maze.size();
        int n = maze[0].size();
        int count = 0;
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                pair<int, int>p = q.front();
                q.pop();
                int row = p.first, col = p.second;
                if(row != entrance[0] || col != entrance[1])
                {
                    if(row == 0 || row == m-1 || col == 0 || col == n-1)
                    {
                        return count;
                    }
                }
                maze[row][col] = '+';
                int up = row-1;
                int down = row+1;
                int left = col-1;
                int right = col+1;
                if(up >= 0 && maze[up][col] == '.')
                {
                    q.push({up, col});
                    maze[up][col] = '+';
                }
                if(down < m && maze[down][col] == '.')
                {
                    q.push({down, col});
                    maze[down][col] = '+';
                }
                if(left >= 0 && maze[row][left] == '.')
                {
                    q.push({row, left});
                    maze[row][left] = '+';
                }
                if(right < n && maze[row][right] == '.')
                {
                    q.push({row, right});
                    maze[row][right] = '+';
                }
            }
            count++;
        }
        return -1;
    }
};