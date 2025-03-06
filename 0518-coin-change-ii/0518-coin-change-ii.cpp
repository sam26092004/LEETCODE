class Solution {
public:
    int ways(int amount, vector<int>& coins,int idx, vector<vector<int>>&dp) {
        if (idx == coins.size())
            return (amount == 0) ? 1 : 0;
        if (amount == 0)
            return 1;
        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        int cnt = 0;
        if (amount >= coins[idx]) {
            cnt += ways(amount - coins[idx], coins, idx, dp);
        }
        cnt += ways(amount, coins, idx + 1, dp);
        return dp[idx][amount] = cnt;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return ways(amount, coins, 0, dp);
    }
};