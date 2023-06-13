class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<string, int>col;
        for(int j=0; j<n; j++)
        {
            string s="";
            for(int i=0; i<n; i++)
            {
                s+=to_string(grid[i][j] + ' ');
            }
            col[s]++;
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            string s="";
            for(int j=0; j<n; j++)
            {
                s+=to_string(grid[i][j]+ ' ');
            }
            if(col.count(s)) ans+=col[s];
        }
        return ans;
    }
};

// 11 1
// 1  11
