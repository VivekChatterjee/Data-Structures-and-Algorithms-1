// 1/11/22 I again started SDE Sheet
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> rowZeroes(r,-1), colZeroes(c,-1);
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rowZeroes[i]=0;
                    colZeroes[j]=0;
                }
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(rowZeroes[i]==0 || colZeroes[j]==0) matrix[i][j]=0;
            }
        }
    }
};