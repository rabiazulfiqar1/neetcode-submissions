class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_cols = matrix[0].size();
        int n_rows = matrix.size();
        int s = 0;
        int e = n_rows - 1;
        while (s<=e) {
            int row = s+(e-s)/2;
            if (target >= matrix[row][0] && target <= matrix[row][n_cols-1]) {
                int l=0, r=n_cols-1;
                while (l<=r) {
                    int mid = l+(r-l)/2;
                    if (matrix[row][mid] == target) return true;
                    if (matrix[row][mid] < target) l = mid+1;
                    else r = mid-1;
                }
                return false;
            } 
            if (target < matrix[row][0]) e = row-1;
            else s = row+1;
        }
        return false;
    }
};
