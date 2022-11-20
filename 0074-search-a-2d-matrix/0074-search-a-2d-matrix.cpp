class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0, end = m*n-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int number = matrix[mid/n][mid%n];
            if(number == target) return 1;
            else if(number < target) start = mid+1;
            else end = mid-1;
        }
        return 0;
    }
};