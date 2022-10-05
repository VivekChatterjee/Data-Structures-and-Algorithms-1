class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        
        int s=0,e=r*c-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            int row=mid/c;
            int col=mid%c;
            
            if(matrix[row][col] == target)
                return 1;
            
            else if(matrix[row][col] > target)
                e=mid-1;
            
            else
                s=mid+1;
        }
        return 0;
    }
};