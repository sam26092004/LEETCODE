class Solution {
public:
    int generateString(const string& s, int idx,
                       vector<vector<bool>>& dp1,
                       vector<int>& dp2) {
        if (idx == s.size()) {
            return 0;
        }

        if (dp2[idx] != -1) return dp2[idx]; 

        int ans = INT_MAX;
        for (int i = idx; i < s.size(); i++) {
            if (dp1[idx][i]) {
                ans = min(ans, 1 + generateString(s, i + 1, dp1, dp2));
            }
        }
        return dp2[idx] = ans;
    }

    int minCut(string s) {
        int n = s.size();

      
        vector<vector<bool>> dp1(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int idx = 0; idx <= n - len; idx++) {
                int k = idx + len - 1;
                if (len == 1) {
                    dp1[idx][idx] = true;
                } else if (len == 2) {
                    dp1[idx][k] = (s[idx] == s[k]);
                } else {
                    dp1[idx][k] = (s[idx] == s[k] && dp1[idx + 1][k - 1]);
                }
            }
        }

       
        vector<int> dp2(n, -1);

        int ans = generateString(s, 0, dp1, dp2);
        return (ans == INT_MAX) ? -1 : ans - 1; 
    }
};