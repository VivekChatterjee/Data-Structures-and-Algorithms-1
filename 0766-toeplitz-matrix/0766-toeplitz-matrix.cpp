class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
            {
            int num=matrix[i][0];
            int s=i,e=0;
            while(s<m && e<n)
                {
                if(matrix[s][e]!=num)
                    return 0;
                s++;
                e++;
                }
            }
            for(int j=1;j<n;j++)
            {
            int num=matrix[0][j];
            int s=j,e=0;
            while(s<n && e<m)
                {
                if(matrix[e][s] != num)
                    return 0;
                s++;
                e++;
                }
            }
        return 1;
    }
};