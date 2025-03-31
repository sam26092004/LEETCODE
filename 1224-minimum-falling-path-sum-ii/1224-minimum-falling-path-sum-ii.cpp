class Solution {
public:
    int minFallingSum(int row, int prevCol, vector<vector<int>>& grid,
                      vector<vector<int>>& dp) {
        if (row == grid.size())
            return 0;
        if (dp[row][prevCol + 1] != -1)
            return dp[row][prevCol + 1];
        int ans = INT_MAX;
        for (int col = 0; col < grid[0].size(); col++) {
            if (col == prevCol)
                continue;
            ans = min(ans,
                      grid[row][col] + minFallingSum(row + 1, col, grid, dp));
        }
        return dp[row][prevCol + 1] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

      
        for (int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }

       
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mini = INT_MAX; 
                                   
                for (int k = 0; k < n; k++) {
                    if (j != k)
                        mini = min(mini, dp[i - 1][k]);
                }
                dp[i][j] = mini + grid[i][j];
            }
        }

       
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};