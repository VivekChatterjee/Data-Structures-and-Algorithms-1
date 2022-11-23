class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, int>m;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                int brd = (i / 3) * 3 + (j / 3);
                if(board[i][j] != '.')
                {
                    string box = "box="+to_string(brd)+" "+board[i][j];
                    string row = "row="+to_string(i)+" "+board[i][j];
                    string col = "col="+to_string(j)+" "+board[i][j];
                    if(m.count(box) || m.count(row) || m.count(col)) return 0;
                    else
                    {
                        m[box]++;
                        m[row]++;
                        m[col]++;
                    }
                }
            }
        }
        return 1;
    }
};