class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string,int>m;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    string row = "row="+to_string(i)+" "+to_string(board[i][j]);
                    string col = "col="+to_string(j)+" "+to_string(board[i][j]);
                    string box= "box="+ to_string((i/3)*3 + (j/3))+" "+to_string(board[i][j]);
                    
                    if(!m.count(row) && !m.count(col) && !m.count(box))
                    {
                        m[row]++;
                        m[col]++;
                        m[box]++;
                    }
                    else
                        return 0;
                }
            }
        }
        
        return 1;
    }
};