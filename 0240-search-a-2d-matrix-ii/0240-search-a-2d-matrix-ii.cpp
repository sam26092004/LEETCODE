class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int startRow = 0, startCol = cols - 1;

        while (startRow < rows && startCol >= 0) {

            if (target == matrix[startRow][startCol])
                return true;
            else if (target < matrix[startRow][startCol])
                startCol--;
            else
                startRow++;
        }
        return false;
    }
};
