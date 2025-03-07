#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int maxValue(vector<vector<int>>& piles, int k, int row, vector<vector<int>>& prefixSum, vector<vector<int>>& dp) {
        if (row == piles.size() || k == 0)
            return 0;
        if (dp[row][k] != -1)
            return dp[row][k];

        int ans = maxValue(piles, k, row + 1, prefixSum, dp); 
        for (int j = 0; j < piles[row].size(); j++) {
            if (j + 1 <= k) {
                ans = max(ans, prefixSum[row][j] + maxValue(piles, k - (j + 1), row + 1, prefixSum, dp));
            }
        }
        return dp[row][k] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        if (piles.empty()) return 0;

        int n = piles.size();
        vector<vector<int>> prefixSum(n);

       
        for (int i = 0; i < n; i++) {
            int m = piles[i].size();
            prefixSum[i].resize(m);
            prefixSum[i][0] = piles[i][0];
            for (int j = 1; j < m; j++) {
                prefixSum[i][j] = prefixSum[i][j - 1] + piles[i][j];
            }
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return maxValue(piles, k, 0, prefixSum, dp);
    }
};
