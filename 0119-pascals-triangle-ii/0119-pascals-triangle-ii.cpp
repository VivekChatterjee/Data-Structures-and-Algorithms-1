class Solution {
public:
    vector<int> getRow(int row) {
        vector<int>ans;
        vector<vector<int>>tri(row+1);
        for(int i=0;i<=row;i++)
        {
            tri[i].resize(i+1);
            tri[i][0] = tri[i][i] = 1;
            for(int j=1;j<i;j++)
            {
                tri[i][j]=tri[i-1][j-1]+tri[i-1][j];
            }
            if(i==row)
                ans.insert(ans.begin(),tri[i].begin(),tri[i].end());
        }
        return ans;
    }
};