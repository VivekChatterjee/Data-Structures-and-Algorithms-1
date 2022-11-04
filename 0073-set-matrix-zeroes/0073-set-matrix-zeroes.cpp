// 1/11/22 I again started SDE Sheet
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        // for 0th column
        int colZero=-1;
        for(int i=0; i<r; i++)
        {
            //0th col is considered here
            if(matrix[i][0] == 0) colZero=0;
            for(int j=1; j<c; j++)
            {
                if(matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for(int i=r-1; i>=0; i--)
        {
            for(int j=c-1; j>0; j--)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j]=0;
            }
            if(colZero == 0) matrix[i][0]=0;
        }
    }
};