class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}};
    vector<vector<vector<vector<int>>>> dp;

    bool isPossible(pair<int, int> coordinates, vector<vector<int>>& grid) {
        return coordinates.first >= 0 && coordinates.first < grid.size() &&
               coordinates.second >= 0 && coordinates.second < grid[0].size() &&
               grid[coordinates.first][coordinates.second] != -1;
    }

    int cherries(pair<int, int> idx1, pair<int, int> idx2,
                 vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if (!isPossible(idx1, grid) || !isPossible(idx2, grid)) {
            return -1e9;
        }

        if (idx1.first == n - 1 && idx1.second == m - 1) {
            return grid[idx1.first][idx1.second];
        }
        if (dp[idx1.first][idx1.second][idx2.first][idx2.second] != -1)
            return dp[idx1.first][idx1.second][idx2.first][idx2.second];

        int cherry = grid[idx1.first][idx1.second];
        if (idx1 != idx2) {
            cherry += grid[idx2.first][idx2.second];
        }

        int maxCherry = -1e9;
        for (auto const& dir1 : directions) {
            for (auto const& dir2 : directions) {
                pair<int, int> newIdx1 = {idx1.first + dir1[0],
                                          idx1.second + dir1[1]};
                pair<int, int> newIdx2 = {idx2.first + dir2[0],
                                          idx2.second + dir2[1]};

                maxCherry = max(maxCherry, cherries(newIdx1, newIdx2, grid));
            }
        }

        return dp[idx1.first][idx1.second][idx2.first][idx2.second] =
                   cherry + maxCherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<vector<vector<int>>>(
                         m, vector<vector<int>>(n, vector<int>(m, -1))));
        if (grid[0][0] == -1 || grid[n - 1][m - 1] == -1)
            return 0;

        int result = cherries({0, 0}, {0, 0}, grid);
        return max(0, result);
    }
};
