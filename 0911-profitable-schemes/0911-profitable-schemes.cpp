class Solution {
public:
int mod=1e9+7;
    int ways(int reward, int idx, int n, int minProfit, vector<int>& group,
             vector<int>& profit, vector<vector<vector<int>>>&dp) {
        if (idx == profit.size()) {
            return (reward >= minProfit) ? 1 : 0;
        }
        if (dp[reward][idx][n] != -1)
            return dp[reward][idx][n];
        int cnt = 0;
        if (n >= group[idx])
            cnt =(cnt+ ways(reward + profit[idx], idx + 1, n - group[idx],
                        minProfit, group, profit,dp))%mod;
         cnt =(cnt+ ways(reward, idx + 1, n, minProfit, group, profit,dp))%mod;
        return dp[reward][idx][n] = cnt;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        int sum = accumulate(profit.begin(), profit.end(), 0);
        vector<vector<vector<int>>>dp(sum+1,vector<vector<int>>(group.size(), vector<int>(n+1,-1)));
        return ways(0,0,n,minProfit,group,profit,dp)%mod;
    }
};