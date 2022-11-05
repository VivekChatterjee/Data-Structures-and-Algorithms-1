class Solution {
public:
    bool search(int k, int i, int j, vector<vector<char>> &board, string word)
    {
        int m=board.size();
        int n=board[0].size();
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] != word[k]) return 0;
        if(k == word.size()-1)
        {
            if(board[i][j] == word[k]) return 1;
            else return 0;
        }
        board[i][j]-=60;
        bool left=0, right=0, up=0, down=0;
        // left
        left = search(k+1, i, j-1, board, word);
        // right
        right = search(k+1, i, j+1, board, word);
        // up
        up = search(k+1, i-1, j, board, word);
        // down
        down = search(k+1, i+1, j, board, word);
        board[i][j]+=60;
        return (left || right || up || down);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m =board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(search(0, i, j, board, word)) return 1;
                }
            }
        }
        return 0;
    }
};