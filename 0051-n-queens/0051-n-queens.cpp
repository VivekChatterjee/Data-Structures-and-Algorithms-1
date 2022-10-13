#define vc vector
class Solution {
public:
    vc<vc<string>>ans;
    bool isSafe(int r, int c, vc<string>v, int n)
    {
        int row=r;
        int col=c;
       // upper left diagonal
        while(row>=0 && col>=0)
        {
            if(v[row][col]=='Q') return 0;
            row--;
            col--;
        }
        row=r;
        col=c;
        // left 
        while(col>=0)
        {
            if(v[row][col]=='Q') return 0;
            col--;
        }
        row=r;
        col=c;
        // lower left diagonal
        while(row<n && col>=0)
        {
            if(v[row][col]=='Q') return 0;
            row++;
            col--;
        }
        return 1;
    }
    void solve(int col, int n, vc<string>v)
    {
        if(col == n)
        {
            ans.push_back(v);
            return;
        }
        for(int row=0; row<n; row++)
        {
            if(isSafe(row, col, v, n))
            {
                v[row][col] = 'Q';
                solve(col+1, n, v);
                v[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vc<string>v(n,s);
        solve(0, n, v);
        return ans;
    }
};