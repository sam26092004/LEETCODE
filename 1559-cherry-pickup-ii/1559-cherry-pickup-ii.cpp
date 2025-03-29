class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> directions = {{1, -1}, {1, 0}, {1, 1}};
    bool isPossible(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && row < grid.size() && col >= 0 &&
               col < grid[0].size();
    }

    int cherries(int row, int col1, int col2, vector<vector<int>>& grid) {

        if (!isPossible(row, col1, grid) || !isPossible(row, col2, grid)) {
            return -1e8;
        }
        if (dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }
        int cherry = grid[row][col1];
        if (col1 != col2) {
            cherry += grid[row][col2];
        }
        int maxCherry = 0;
        for (auto const& dir1 : directions) {
            for (auto const& dir2 : directions) {
                pair<int, int> idx1 = {row + dir1[0], col1 + dir1[1]};
                pair<int, int> idx2 = {row + dir2[0], col2 + dir2[1]};
                maxCherry = max(maxCherry, cherries(idx1.first, idx1.second,
                                                    idx2.second, grid));
            }
        }
        return dp[row][col1][col2] = cherry + maxCherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        dp.resize(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        return cherries(0, 0, cols - 1, grid);
    }
};